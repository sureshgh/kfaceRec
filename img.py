#!/usr/bin/python
import cv2 #Import functions from OpenCV

import cv #Import functions from OpenCV
cv.NamedWindow('a_window', cv.CV_WINDOW_AUTOSIZE)
image=cv.LoadImage('picture.png', cv.CV_LOAD_IMAGE_GRAYSCALE) #Load the image
font = cv.InitFont(cv.CV_FONT_HERSHEY_SIMPLEX, 1, 1, 0, 3, 12) #Creates a font
x = 800
y = 600
cv.PutText(image,"Hello World!!!", (x,y),font, 255) #Draw the text
cv.putText(image, "your_string", (100,100), font, 228)
cv.ShowImage('a_window', image) #Show the image
#cv.Waitkey(10000)
cv.SaveImage('image.png', image) #Saves the image
