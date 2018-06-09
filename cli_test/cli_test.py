import serial
import time

def test_cli_commad (ser, cmd, timeout=0.3):
	print "------------------------------"
	ser.write(cmd)
	time.sleep(timeout)
	n_bytes = ser.in_waiting
	response = ser.read(n_bytes);
	print response
	print "------------------------------"

def test_SendSegment (ser):
	print "------------------------------"
	segment_len = 4096
	segment = [0]*(segment_len+2)
	ser.write("SendSegment {}\r\n".format(segment_len))
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
	
	test_cli_commad(ser, "GetPlcStatus\r\n")
	test_cli_commad(ser, "Boot\r\n", 5)
	test_cli_commad(ser, "ResetDownload\r\n")
	test_SendSegment(ser)
	#test_SendSegment(ser)
	#test_SendSegment(ser)
	#test_SendSegment(ser)
	print "------------------------------"
	#print "After test_SendSegment"
	test_cli_commad(ser, "ResetDownload\r\n")
	test_cli_commad(ser, "SendTotalCRC\r\n")
	test_cli_commad(ser, "RunUserApp\r\n")

	ser.close()