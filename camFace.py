#!/usr/bin/python
import cv
import serial
 
HAAR_CASCADE_PATH = "/home/suraysh/Desktop/python/haarcascade_frontalface_default.xml"
CAMERA_INDEX = 0
font = cv.InitFont(cv.CV_FONT_HERSHEY_SIMPLEX, 1, 1, 0, 3, 12) 

def detect_faces(image):
    faces = []
    detected = cv.HaarDetectObjects(image, cascade, storage, 1.2, 2, cv.CV_HAAR_DO_CANNY_PRUNING, (100,100))
    if detected:
        for (x,y,w,h),n in detected:
            faces.append((x,y,w,h))
    return faces
 
if __name__ == "__main__":
    cv.NamedWindow("Video", cv.CV_WINDOW_AUTOSIZE)
 
    capture = cv.CaptureFromCAM(CAMERA_INDEX)
    storage = cv.CreateMemStorage()
    cascade = cv.Load(HAAR_CASCADE_PATH)
    faces = []
    c = -1
    i=0

    while (c == -1):
        image = cv.QueryFrame(capture)
         if i%5==0:
            faces = detect_faces(image)
 
        for (x,y,w,h) in faces:
            cv.Rectangle(image, (x,y), (x+w,y+h), 255)
            cv.PutText(image,"Hello Suresh", (x+20,y-20),font, 255) 
            ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
            ser.write("at")      # write a string
            ser.write("\n\r")
            rec = ser.read(10)
            print rec
            cv.PutText(image,rec, (x+w+20,y+w-20),font, 255) 
            line = ser.readline()    
            #print rec
            ser.write("atd9849616965\n\r")      # write a string
            ser.flush()
            s=ser.read(20)
            line = ser.readline()   # read a '\n' terminated line
            ser.close()
        cv.ShowImage("Video", image)
        i += 1
        c = cv.WaitKey(10)


