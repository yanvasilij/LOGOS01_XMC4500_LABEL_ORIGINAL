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

	test_cli_commad(ser, "RunUserApp\r\n", 5)