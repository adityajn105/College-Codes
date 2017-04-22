import pygame.camera

import numpy

import scipy

import time

from scipy import ndimage #This package contains various functions for multi-dimensional image processing.

from Tkinter import * #The Tkinter module ("Tk interface") is the standard Python interface to the Tk GUI toolkit.

from PIL import Image, ImageTk

i=0
#export PYGAME_CAMERA=opencv

#capturing image from camera

pygame.camera.init()   #initialising the camera

cam = pygame.camera.Camera("/dev/video0",(320,240))  #to select the cam and the required resolution

cam.start()  #start the cam

img = cam.get_image()   #click the image

import pygame.image
pygame.image.save(img,"/image3.jpg")

pygame.camera.quit()

import cv2

img2=cv2.imread("/image3.jpg",0)
cv2.imshow("orignal",img2)

scale=1
delta=0
ddepth=cv2.CV_16S

sobelx = cv2.Sobel(img2,cv2.CV_32F,1,0,ksize=3)
sobely = cv2.Sobel(img2,cv2.CV_32F,0,1,ksize=3)

abs_sobelx = cv2.convertScaleAbs(sobelx)
abs_sobely = cv2.convertScaleAbs(sobely)

dst = abs_sobelx + abs_sobely # cv2.addWeighted(abs_sobelx,0.5,abs_sobely,0.5,0)



cv2.imshow('image',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
