#!/usr/bin/python
import serial


#require "serialport.so"
#require 'webrick';

SERIALPORT="/dev/ttyUSB0"

s =  HTTPServer.new( :Port => 2000 )

class DemoServlet < HTTPServlet::AbstractServlet
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
end
s.mount( "/test", DemoServlet )
trap("INT"){ s.shutdown }
s.start

