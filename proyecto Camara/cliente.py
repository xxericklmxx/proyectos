# -*- coding: utf-8 -*-
"""
Created on Sat May 16 18:25:04 2020

@author: erickmg
"""


import cv2
import socket
import matplotlib as mp
import pickle as pl
import numpy as np

buff=512
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(('192.168.0.9',6500))
inicio=b'inicio'
itera=1800
while True:  
    frames=[]
    empezar=False
    while(len(frames)<itera):
        frame=s.recv(buff)
        if(empezar):
            frames.append(frame)
        elif(frame.startswith(inicio)):
            empezar=True
    bytes_frame=b''.join(frames)
    if(len(bytes_frame)<921600):
        for i in range(0,921600-len(bytes_frame)):
            bytes_frame+=b'0'
    frame=np.frombuffer(bytes_frame, dtype=np.uint8).reshape(480, 640, 3)
    
    cv2.imshow('video',frame)
    if(cv2.waitKey(1) & 0xFF == ord('q')):
            break
cap.release()
cv2.destroyAllWindows()