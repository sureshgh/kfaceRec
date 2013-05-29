#!/usr/bin/python
import serial

while 1:
	ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=0, parity=serial.PARITY_EVEN, rtscts=1)  # open first serial port
	#print ser.portstr       # check which port was really used
	#ser.write("at")      # write a string
	#ser.write("\n\r")
	#ser.close()             # close port
	
	#ser = serial.Serial('/dev/ttyACM1', 9600, timeout=1)  # open first serial port
	#rec = ser.read(100)  
	line =ser.readline(size=14)
	#line = ser.readline()    
	print line
		       
	#ser.write("atd9849616965\n\r")   
	ser.close() 
