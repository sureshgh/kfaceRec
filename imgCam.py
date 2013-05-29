#!/usr/bin/python
import cv
import cv2





if __name__ == "__main__":
	print "Press ESC to exit ..."

# create windows
cv.NamedWindow('Raw', cv.CV_WINDOW_AUTOSIZE)
cv.NamedWindow('Processed', cv.CV_WINDOW_AUTOSIZE)

# create capture device
device = 0 # assume we want first device
capture = cv.CaptureFromCAM(0)
cv.SetCaptureProperty(capture, cv.CV_CAP_PROP_FRAME_WIDTH, 640)
cv.SetCaptureProperty(capture, cv.CV_CAP_PROP_FRAME_HEIGHT, 480)
font = cv.InitFont(cv.CV_FONT_HERSHEY_SIMPLEX, 1, 1, 0, 3, 12) #Creates a font


# check if capture device is OK
if not capture:
    print "Error opening capture device"
    sys.exit(1)

while 1:
    # do forever
	# capture the current frame

    frame = cv.QueryFrame(capture)
    if frame is None:
        break

    cv.ShowImage('Raw', frame)   
    cv.Flip(frame, None, 1)
	#cv.PutText(frame,"Hello World!!!", (300,400),font, 255) 
	

    # face detection
    #detect(frame)

    # display webcam image
    cv.ShowImage('Processed', frame)


    # handle events
    k = cv.WaitKey(10)

    if k == 0x1b: # ESC
        print 'ESC pressed. Exiting ...'
        break

   	if k == 0x63 or k == 0x43:
   		print 'capturing!'
    	cv.SaveImage("test.jpg",frame) 
