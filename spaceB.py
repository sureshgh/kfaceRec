#!/usr/bin/env python

#import json
import serial

ser = serial.Serial(
    port='/dev/ttyUSB0',
    baudrate=9600,
    bytesize=8,
    parity='N',
    stopbits=1,
    timeout=1)

ser.open()
while True:
    s = ser.readline()
    print s
    
