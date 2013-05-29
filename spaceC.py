#!/usr/bin/python
import serial

import sys
import BaseHTTPServer
from SimpleHTTPServer import SimpleHTTPRequestHandler


HandlerClass = SimpleHTTPRequestHandler
ServerClass  = BaseHTTPServer.HTTPServer
Protocol     = "HTTP/1.0"
port = 8000
server_address = ('127.0.0.1', port)

    def getValue()
       	begin
            ser = serial.Serial(port='/dev/ttyUSB0',baudrate=9600,bytesize=8,parity='N',stopbits=1,timeout=1)
            #sp.read_timeout = 500
            #sp.write( "... whatever you like to send to your arduino" )
            p = ser.readline()
            print p
            #sp.close
            return body
        rescue
            puts "cant open serial port"
        end
    end

    def do_GET( req, res )

        body = "--.--"
        body = getValue()

        res.body = body
        res['Content-Type'] = "text/plain"
    end

HandlerClass.protocol_version = Protocol
httpd = ServerClass(server_address, HandlerClass)



print "Serving HTTP on"
httpd.serve_forever()
