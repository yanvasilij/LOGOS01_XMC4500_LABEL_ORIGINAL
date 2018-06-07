/**
 * @brief Command line interface
 * @author Yanikeev Vasily (yanvasilij@gmail.com)
 */

#include <DAVE3.h>
#include "stdio.h"

/**********************************************************************************************************************
 * 						crc calculation
**********************************************************************************************************************/
#define		P_16        	0xA001		/**< \def Polynom */
#define 	DATA_MAX_LEN	256			/**< \def Modbus RTU packet data len */
volatile static uint16_t   crc_tab16[ DATA_MAX_LEN ];

static void init_crc16_tab( void )
{
	uint32_t i, j;
	uint16_t crc, c;

	for ( i=0; i < DATA_MAX_LEN; ++i )
	{
		crc = 0;
		c = i;
		for ( j = 0; j < 8; ++j )
		{
			if ( ( crc ^ c ) & 0x0001 )
			{
				crc = ( crc >> 1 ) ^ P_16;
			}
			else
			{
				crc =   crc >> 1;
			}
			c = c >> 1;
		}
		crc_tab16[ i ] = crc;
	}
} 

/**
 * @brief CRC calculation 
 *   The function update_crc_16 calculates a  new  CRC-16  value based  on  the  previous value of the CRC and the next 
 *   byte of the data to be checked.
 *
 */
static uint16_t update_crc_16( uint16_t crc, uint8_t c )
{
    uint16_t tmp, short_c;
    short_c = 0x00ff & ( uint16_t ) c;
    tmp =  crc         ^ short_c;
    crc = ( crc >> 8 ) ^ crc_tab16[ tmp & 0xff ];
    return crc;
}

uint16_t calcCrc (uint8_t *data, uint32_t len)
{
	uint16_t crc_16_modbus  = 0xffff;

	init_crc16_tab( );
    for ( uint32_t i = 0; i < len; ++i )
    {
        crc_16_modbus = update_crc_16( crc_16_modbus, data [ i ] );
    }
	return crc_16_modbus;
}

/**********************************************************************************
*				eof
**********************************************************************************/
