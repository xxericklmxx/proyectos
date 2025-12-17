package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

type solicitud struct {
	id        int
	respuesta chan bool
	liberar   bool
}

func coordinador(solicitudes <-chan solicitud) {
	platos := [5]bool{false, false, false, false, false}

	for req := range solicitudes {
		if req.liberar {
			platos[req.id] = false
			fmt.Printf("Filósofo %d liberó el plato %d\n", req.id, req.id)
			req.respuesta <- true
		} else {
			izq := (req.id + 4) % 5
			der := (req.id + 1) % 5

			if !platos[req.id] && !platos[izq] && !platos[der] {
				platos[req.id] = true
				fmt.Printf("Filósofo %d tiene permiso para comer en plato %d\n", req.id, req.id)
				req.respuesta <- true
			} else {
				fmt.Printf("Filósofo %d NO puede comer en plato %d ahora\n", req.id, req.id)
				req.respuesta <- false
			}
		}
	}
}

func filosofo(id int, solicitudes chan<- solicitud, wg *sync.WaitGroup) {
	defer wg.Done()

	rnd := rand.New(rand.NewSource(time.Now().UnixNano() + int64(id)))

	for i := 0; i < 3; i++ { // cada filósofo come 3 veces
		// Pensando
		fmt.Printf("Filósofo %d está pensando...\n", id)
		time.Sleep(time.Duration(rnd.Intn(1000)+500) * time.Millisecond)

		// Pedir permiso para comer
		resp := make(chan bool)
		solicitudes <- solicitud{id: id, respuesta: resp, liberar: false}

		// Esperar respuesta
		puedeComer := <-resp
		if !puedeComer {
			// No pudo comer, espera un poco y lo intenta otra vez
			fmt.Printf("Filósofo %d espera para volver a pedir permiso\n", id)
			time.Sleep(time.Duration(rnd.Intn(1000)+500) * time.Millisecond)
			i-- // no cuenta esta iteración como comida, intenta otra vez
			continue
		}

		// Comiendo
		fmt.Printf("Filósofo %d está comiendo en plato %d\n", id, id)
		time.Sleep(time.Duration(rnd.Intn(1000)+500) * time.Millisecond)

		// Liberar plato
		solicitudes <- solicitud{id: id, respuesta: resp, liberar: true}
		<-resp // Esperar confirmación de liberación
	}
	fmt.Printf("Filósofo %d terminó de comer todas sus veces\n", id)
}

func main() {
	solicitudes := make(chan solicitud)

	go coordinador(solicitudes)

	var wg sync.WaitGroup
	for i := 0; i < 5; i++ {
		wg.Add(1)
		go filosofo(i, solicitudes, &wg)
	}

	wg.Wait()
	close(solicitudes)

	fmt.Println("Todos los filósofos terminaron.")
}
