import serial
import time
from cli_test import test_cli_commad

def test_cli_commad (cmd):

if __name__ == "__main__":
	
	ser = serial.Serial('COM5', timeout=0.2)
	print(ser.name)

	openning_sequence = [1,1,0,8,8,1]	
	
	test_cli_commad("Hex\r\n", 0.5)

	ser.close()