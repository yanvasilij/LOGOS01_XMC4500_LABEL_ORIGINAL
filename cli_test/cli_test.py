import serial
import time

def test_cli_commad (cmd):
	print "------------------------------"
	ser.write(cmd)
	time.sleep(0.3)
	n_bytes = ser.in_waiting
	response = ser.read(n_bytes);
	print response
	print "------------------------------"

def test_SendSegment ():
	print "------------------------------"
	segment_len = 4096
	segment = [0]*(segment_len+2)
	ser.write("SendSegment {}\r\n".format(segment_len))
	time.sleep(0.010)
	ser.write(segment)
	time.sleep(5)
	n_bytes = ser.in_waiting
	response = ser.read(n_bytes);
	print response	
	print "------------------------------"

if __name__ == "__main__":
	
	ser = serial.Serial('COM5', timeout=0.2)
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
	test_SendSegment()
	test_SendSegment()
	test_SendSegment()
	print "------------------------------"
	#print "After test_SendSegment"
	test_cli_commad("ResetDownload\r\n")
	test_cli_commad("SendTotalCRC\r\n")
	test_cli_commad("RunUserApp\r\n")

	ser.close()