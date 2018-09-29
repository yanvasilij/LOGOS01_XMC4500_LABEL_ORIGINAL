import serial
import time
import struct


def test_cli_commad (ser, cmd, timeout=0.3):
	print "------------------------------"
	ser.write(cmd)
	time.sleep(timeout)
	n_bytes = ser.in_waiting
	response = ser.read(n_bytes);
	print response
	bin_data = response[8:]
	#print ("total len", len(bin_data))
	#tick = struct.unpack('<L',  bin_data[0:4])[0]
	#print("tick", tick)
	res = ":".join("{:02x}".format(ord(x)) for x in bin_data)
	print("res", res)

	#my_data = struct.unpack('h',  bin_data[4:6])[0]
	#print("my_data", my_data)

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
	
	test_cli_commad(ser, "GetDbg\r\n", 1)

	ser.close()