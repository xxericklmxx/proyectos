package main

import (
	"html/template"
	"net/http"
)

func inicio(w http.ResponseWriter, req *http.Request) {
	tlp, _ := template.ParseFiles("templates/index.gohtml")
	tlp.Execute(w, nil)
}

func main() {
	http.HandleFunc("/", inicio)
	http.Handle("/resources/pics/", http.StripPrefix("/resources/pics/", http.FileServer(http.Dir("public/pics"))))
	http.ListenAndServe(":8080", nil)
}
