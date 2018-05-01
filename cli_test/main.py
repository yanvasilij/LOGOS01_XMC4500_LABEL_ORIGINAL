import serial
import time
ser = serial.Serial('COM4')
print(ser.name)

openning_sequence = [1,1,0,8,8,1]

ser.write(openning_sequence)
time.sleep(0.1)
ser.write("GetPlcStatus\r\n");
time.sleep(0.1)
n_bytes = ser.in_waiting
response = ser.read(n_bytes);

print response

ser.close()