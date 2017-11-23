import numpy as np
import cv2

img = cv2.imread('2017-11-15 18.13.41.jpg', cv2.IMREAD_COLOR)

height, width, channel = img.shape

print(height, width)

for y in range(0, height):
    for x in range(0, width):

'''
def showImage():
    imgfile = '2017-11-15 18.13.41.jpg'
    img = cv2.imread(imgfile, cv2.IMREAD_COLOR)

    cv2.imshow('model', img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

showImage()
'''
