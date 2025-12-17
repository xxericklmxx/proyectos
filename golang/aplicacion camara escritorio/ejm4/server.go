package main

import (
	"fmt"
	"log"
	"net"

	"gocv.io/x/gocv"
)

var ancho = 640
var alto = 480
var buffer = 1024
var image2 gocv.Mat

func main() {
	x := 0
	li, err := net.Listen("tcp", "192.168.0.9:8000")
	if err != nil {
		log.Panic(err)
	}
	defer li.Close()
	for {
		con, err := li.Accept()
		if err != nil {
			log.Panic(err)
		}
		x += 1
		go servir(con, string(x))

	}

}
func servir(c net.Conn, n string) {

	window := gocv.NewWindow(n)
	rec := make([]byte, 921600)
	for {

		c.Read(rec)

		if len(rec) != 0 {

			image2, err := gocv.NewMatFromBytes(480, 640, gocv.MatTypeCV8UC3, rec)

			if err != nil {
				fmt.Println("fuentes!", err)
			}
			if window.WaitKey(1) == 27 {
				break
			}
			window.IMShow(image2)
		}

		defer window.Close()
	}

}
