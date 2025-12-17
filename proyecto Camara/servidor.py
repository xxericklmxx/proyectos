# -*- coding: utf-8 -*-
"""
Created on Sun May 17 19:58:23 2020

@author: erickmg
"""


import socket
import cv2
import threading,_thread
import numpy as np
import time
import multiprocessing
from multiprocessing import current_process
from matplotlib import pyplot as plt
import pyaudio
buffer=1024
inicio=b'inicio'
ancho=640
alto=480
iteracion=(ancho*alto*3)/buffer
mensajes=''
clientes=''
tam=ancho*alto*3
l=[] 
def camara(cliente,puerto):
    con=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)   
    con.bind(('192.168.0.9',puerto))            
    print(cliente) 
    m=con.recvfrom(buffer)   
    while(True):               
        datos=[]
        empezar=False
        while(len(datos)<iteracion):
            data,cenvia=con.recvfrom(buffer)                                             
            if(empezar and (cliente[0] in cenvia)):
                datos.append(data)
            elif(data.startswith(inicio)and (cliente[0] in cenvia)):
                empezar=True            
        frame=b''.join(datos)        
        if(len(frame)<tam):
            for i in range(0,tam-len(frame)):
                frame+=b'0'
        frame=np.frombuffer(frame, dtype=np.uint8).reshape(480, 640, 3) 
        cv2.imshow(str(cliente),frame)
        if(cv2.waitKey(1) & 0xFF == ord('q')):
            cv2.destroyAllWindows() 
def audio(cliente,puerto):
    con=socket.socket(socket.AF_INET,socket.SOCK_STREAM)   
    con.bind(('192.168.0.9',puerto))  
    con.listen(1)             
    print(cliente)    
    formato=pyaudio.paInt16
    canales=1
    ciclos=8000
    p=pyaudio.PyAudio()
    stream=p.open(format=formato,channels=canales,rate=ciclos,output=True)  
    s,cli=con.accept()
    data=[]     
    while(True):
        datos=s.recv(buffer)
        stream.write(datos)
        
      
            
          
           
            
def control():
    host='192.168.0.9'
    port=6500    
    puerto=6500
    control=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    control.bind((host,port))       
    control.listen(10)
    while(True):
        s,cliente=control.accept()
        puerto=puerto+1
        print(puerto)
        #q1=multiprocessing.Queue()
        #q.put(cliente)
        p1=multiprocessing.Process(target=audio, args=(cliente,puerto,))
        p1.start()
        print("enviando numeracion audio")
        m=str(puerto)
        s.send(m.encode())
        print("puerto de audio",puerto)
        puerto=puerto+1               
        p2=multiprocessing.Process(target=camara, args=(cliente,puerto,))
        p2.start()
        print("enviando numeracion video")
        m=str(puerto)
        s.send(m.encode())  
        print("puerto de video",puerto) 
        l.append(cliente)
#        lock=threading.Lock()
        #threading.Thread(target=camara,args=(cliente,con,)).start()    
           


    

if __name__ == '__main__':
    control()

    
        
        
    



