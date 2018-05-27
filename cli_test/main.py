import serial
import time

def test_cli_commad (cmd):
	ser.write(cmd)
	time.sleep(0.1)
	n_bytes = ser.in_waiting
	response = ser.read(n_bytes);
	print response

def test_SendSegment ():
	segment = [x for x in range(4096)]
	ser.write("SendSegment 4096\r\n")
	ser.write(segment)
	time.sleep(0.1)
	response = ser.read(n_bytes);
	print response	

if __name__ == "__main__":
	
	ser = serial.Serial('COM4')
	print(ser.name)

	openning_sequence = [1,1,0,8,8,1]
	
	segment = []

	ser.write(openning_sequence)
	time.sleep(0.1)

	ser.write("GetPlcStatus\r\n")
	time.sleep(0.1)
	n_bytes = ser.in_waiting
	response = ser.read(n_bytes)

	test_cli_commad("GetPlcStatus\r\n")
	test_cli_commad("Boot\r\n")
	test_cli_commad("ResetDownload\r\n")
	test_SendSegment()
	test_cli_commad("SendTotalCRC\r\n")
	test_cli_commad("RunUserApp\r\n")

	ser.close()