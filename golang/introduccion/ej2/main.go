package main

import (
	"html/template"
	"log"
	"os"
)

type hotel struct {
	Name    string
	Address string
	City    string
	Zip     int
	Rg      region
}
type region struct {
	Region []string
}

var tpl *template.Template

func init() {
	tpl = template.Must(template.ParseFiles("tpl.gohtml"))
}

func main() {

	h1 := hotel{
		Name:    "hotelaso",
		Address: "av siempre viva",
		City:    "peru",
		Zip:     051,
		Rg: region{
			Region: []string{"Southern", "a la mierda"},
		},
	}
	h3 := hotel{
		Name:    "hotelaso2",
		Address: "av siempre viva2",
		City:    "peru",
		Zip:     051,
		Rg: region{
			Region: []string{"Central"},
		},
	}

	h2 := hotel{
		Name:    "hotelaso",
		Address: "av siempre viva",
		City:    "peru",
		Zip:     051,
		Rg: region{
			Region: []string{"Northern"}},
	}

	hotels := []hotel{h1, h2, h3}
	err := tpl.Execute(os.Stdout, hotels)
	if err != nil {
		log.Fatalln(err)
	}

}
