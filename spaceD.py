#!/usr/bin/env python

from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
import os

#Create custom HTTPRequestHandler class
class KodeFunHTTPRequestHandler(BaseHTTPRequestHandler):
	def do_GET(self):
		print "nepal"
		   
	def run():
		print('http server is starting...')

		#ip and port of servr
		#by default http server port is 8000
		server_address = ('127.0.0.1', 8000)
		httpd = HTTPServer(server_address, KodeFunHTTPRequestHandler)
		print('http server is running...')
		httpd.serve_forever()
		
	if __name__ == '__main__':
		run()
