package main

import (
	"html/template"
	"net/http"
)

var tlp *template.Template

func init() {

	tlp = template.Must(template.ParseFiles("templates/index.gohtml"))
}

func inicio(w http.ResponseWriter, req *http.Request) {

	tlp.Execute(w, nil)

}

func main() {

	http.HandleFunc("/", inicio)
	http.Handle("/public/", http.StripPrefix("/public", http.FileServer(http.Dir("public"))))
	http.ListenAndServe(":8080", nil)
}
