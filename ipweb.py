#!/usr/bin/python
import sys
import cv

video="http://192.168.1.4:8080/browser.html"
capture =cv.CaptureFromFile(video)
cv.NamedWindow('Video Stream', 1 )
while True:
  # capture the current frame
  frame = cv.QueryFrame(capture)
  if frame is None:
    break
  else:
    #detect(frame)
    cv.ShowImage('Video Stream', frame)
  if k == 0x1b: # ESC
    print 'ESC pressed. Exiting ...'
    break
