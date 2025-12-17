package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
	"os"

	"gocv.io/x/gocv"
)

var ancho = 640.0
var alto = 480.0
var buffer = 4096

func main() {

	li, err := net.Dial("tcp", "192.168.0.9:8000")
	if err != nil {
		log.Panic(err)
	}
	defer li.Close()
	scanner2 := bufio.NewScanner(li)
	ln := "A"
	i := 0
	for scanner2.Scan() && i <= 2 {
		ln = scanner2.Text()
		fmt.Println(ln)
		i++
	}

	scanner := bufio.NewScanner(os.Stdin)
	fmt.Printf("ingrese la opcion de resolucion")
	scanner.Scan()
	opcion := scanner.Text()
	switch opcion {
	case "1":
		alto = 120
		ancho = 160
	case "2":
		alto = 240
		ancho = 320
	case "3":
		alto = 480
		ancho = 640
	}
	fmt.Fprintln(li, opcion)
	cam(li, "ab")

}

func cam(c net.Conn, nombre string) {
	webcam, _ := gocv.OpenVideoCapture(0)
	window := gocv.NewWindow(nombre)
	webcam.Set(3, ancho)
	webcam.Set(4, alto)
	img := gocv.NewMat()
	//defer img.Close()
	defer window.Close()
	defer webcam.Close()
	defer c.Close()
	for {
		webcam.Read(&img)
		//s, _ := gocv.IMEncodeWithParams(gocv.JPEGFileExt, img, []int{gocv.IMWriteJpegQuality, 75}) // metodo para convertir a string el buyffer
		x := img.ToBytes()
		//fmt.Println("el valor de x:", len(x))
		//for i := 0; i < len(x); i = i + buffer {
		//	y, _ := c.Write(x[i:(i + buffer)])
		//	fmt.Println(y)
		//}
		c.Write(x)
		//fmt.Println(y)
		//time.Sleep(10 * time.Millisecond)
		if window.WaitKey(1) == 27 {

			break
		}

		window.IMShow(img)
	}

}
