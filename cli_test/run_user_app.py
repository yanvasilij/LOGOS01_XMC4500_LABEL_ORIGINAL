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
	
if __name__ == "__main__":
	
	ser = serial.Serial('COM5', timeout=0.2)
	print(ser.name)
	
	openning_sequence = [1,1,0,8,8,1]
	
	segment = []

	ser.write(openning_sequence)
	time.sleep(0.1)

	test_cli_commad(ser, "RunUserApp\r\n", 5)