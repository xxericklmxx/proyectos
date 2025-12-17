# -*- coding: utf-8 -*-
"""
Created on Sun May 17 15:35:55 2020

@author: erickmg
"""


import socket
import cv2
import pickle as pl
import clasecamara as cc
import multiprocessing
import time
import threading
import pyaudio
buffer=1024
host=socket.gethostbyname(socket.gethostname())
servi='192.168.0.9'
puerto=6500
inicio=b'inicio'
inicio=('inicio'+(buffer-len(inicio))*'a').encode("utf-8")
def enviar_video(p):
    con=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    servidor=(servi,int(p))
    print(type(servidor))
    camara=cc.camara()
    cap=camara.iniciar_camara()
    con.sendto("iniciar".encode(),servidor)
    while(True):
        ret,frame=cap.read()
        captura=frame.tostring()
        con.sendto(inicio,servidor)
        for i in range(0,len(captura),buffer):
            con.sendto(captura[i:i+buffer],servidor)
        time.sleep(0.05)


def enviar_audio(p):    
    con=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    con.connect((servi,int(p)))
    servidor=(servi,int(p)+1)
    print(p)
    buff=int(buffer/2)
    formato=pyaudio.paInt16
    canales=1
    ciclos=8000
    p=pyaudio.PyAudio()
    stream=p.open(format=formato,channels=canales,rate=ciclos,input=True,frames_per_buffer=512)
    while(True):
        data=stream.read(buffer)        
        con.send(data)        
    stream.stop_stream()
    stream.close()
    p.terminate()
    
    
        
def main():   
    control=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    control.bind((host,6499))
    puert=6500
    control.connect((servi,puert))
    print("esperando numeracion")
    p2=control.recv(buffer)
    print(p2)
    print(host)
    p=control.recv(buffer)
    print(p.decode())
    threading.Thread(target=enviar_video,args=(p,)).start()
    threading.Thread(target=enviar_audio,args=(p2,)).start()
       

if __name__ == '__main__':
    main()


