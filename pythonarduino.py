from re import A
import serial
import numpy as np

with serial.Serial('/dev/ttyACM0', 9600) as ser:
	
	
	for i in range(10): 
		x = ser.readline()
		print(x)
		c = f"{i}\n"
		ser.write(c.encode())
		

		y = ser.readline()
		print(y)
	
	ser.close()
