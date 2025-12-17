package main

import (
	"html/template"
	"io"
	"log"
	"net/http"
)

var tpl *template.Template
var tpl1 *template.Template
var tpl2 *template.Template

func init() {
	tpl = template.Must(template.ParseFiles("j1.html"))
	tpl1 = template.Must(template.ParseFiles("j2.html"))
	tpl2 = template.Must(template.ParseFiles("j3.html"))
}

func dog(r http.ResponseWriter, req *http.Request) {
	x := "perrosky"
	err := tpl1.Execute(r, x)
	if err != nil {
		log.Fatalln(err)
	}
	io.WriteString(r, "dog")
}
func me(r http.ResponseWriter, req *http.Request) {
	http.ServeFile(r, req, "perro.jpg")

}
func foo(r http.ResponseWriter, req *http.Request) {
	x := "foo ran"
	err := tpl.Execute(r, x)
	if err != nil {
		log.Fatalln(err)
	}

	io.WriteString(r, "foo ran")
}

func main() {

	http.HandleFunc("/", foo)
	http.HandleFunc("/dog/", dog)
	http.HandleFunc("/perro.jpg", me)
	http.ListenAndServe(":8080", nil)

}
