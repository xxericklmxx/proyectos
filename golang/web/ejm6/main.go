package main

import (
	"net/http"
	"text/template"
)

var tlp *template.Template

func inicio(w http.ResponseWriter, req *http.Request) {
	tlp, _ = template.ParseFiles("templates/index.gohtml")
	tlp.Execute(w, nil)
}

func main() {

	http.HandleFunc("/", inicio)
	fs := http.FileServer(http.Dir("public"))
	http.Handle("/pics/", fs)
	http.ListenAndServe(":8080", nil)
}
