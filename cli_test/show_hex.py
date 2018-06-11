import serial
import time
from cli_test import test_cli_commad


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
	
	test_cli_commad(ser, "Hex 10320\r\n", 1)

	ser.close()