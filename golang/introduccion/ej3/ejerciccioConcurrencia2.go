package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

// Philosopher representa a un comensal con un identificador único.
type Philosopher struct {
	name string
}

// RequestType define el tipo de acción que un filósofo quiere realizar.
type RequestType int

const (
	RequestSeat RequestType = iota // 0: Pide un asiento
	ReleaseSeat                    // 1: Libera un asiento
)

// Request es el mensaje que un filósofo envía al coordinador.
// Incluye un canal de retorno para la respuesta.
type Request struct {
	philosopher *Philosopher
	requestType RequestType
	seatIndex   int      // Solo se usa para liberar un asiento específico.
	replyChan   chan int // El coordinador responde con el índice del asiento, o -1 si no hay lugar.
}

// coordinator es la única goroutine que gestiona el estado de la mesa.
// Es el corazón de nuestro diseño concurrente.
func coordinator(requests chan Request, numSeats int) {
	// El estado de la mesa. Un asiento es nil si está vacío.
	table := make([]*Philosopher, numSeats)
	// El coordinador tiene su propio generador de números aleatorios para ser independiente.
	rnd := rand.New(rand.NewSource(time.Now().UnixNano()))
	fmt.Printf("Mesa preparada con %d asientos.\n", numSeats)

	// Bucle principal: procesa una solicitud a la vez, en orden.
	for req := range requests {
		switch req.requestType {
		case RequestSeat:
			seatFound := -1

			// --- MEJORA CLAVE ---
			// En lugar de empezar siempre en 0, empezamos la búsqueda en un índice aleatorio.
			// Esto hace que la asignación de asientos sea justa e impredecible.
			startIndex := rnd.Intn(len(table))

			// Iteramos el número total de asientos para asegurar que revisamos todos,
			// comenzando desde nuestro punto de partida aleatorio.
			for j := 0; j < len(table); j++ {
				i := (startIndex + j) % len(table) // Asiento actual a revisar (circular)

				left := (i + len(table) - 1) % len(table)
				right := (i + 1) % len(table)

				// Condición: El asiento actual y sus dos vecinos deben estar libres.
				if table[i] == nil && table[left] == nil && table[right] == nil {
					table[i] = req.philosopher
					seatFound = i
					break // Dejar de buscar.
				}
			}
			// Enviar la respuesta (el asiento encontrado o -1) por el canal de retorno.
			req.replyChan <- seatFound

		case ReleaseSeat:
			// Liberar el asiento es una operación simple y segura.
			if req.seatIndex >= 0 && req.seatIndex < len(table) && table[req.seatIndex] != nil {
				fmt.Printf("🪑 Asiento %d ha sido liberado por %s.\n", req.seatIndex, table[req.seatIndex].name)
				table[req.seatIndex] = nil
			}
			// Enviar confirmación de que la operación se completó.
			req.replyChan <- 1
		}
	}
}

// philosopher es la lógica para cada comensal.
func philosopher(p *Philosopher, requests chan Request, wg *sync.WaitGroup) {
	defer wg.Done()
	rnd := rand.New(rand.NewSource(time.Now().UnixNano()))

	// Cada filósofo intenta comer una vez.
	// 1. PENSAR
	fmt.Printf("🤔 %s está pensando...\n", p.name)
	time.Sleep(time.Duration(1000+rnd.Intn(1000)) * time.Millisecond)

	// 2. INTENTAR COMER (puede requerir varios intentos)
	seatIndex := -1
	for {
		fmt.Printf(" hungry %s quiere encontrar un asiento.\n", p.name)
		replyChan := make(chan int)
		requests <- Request{philosopher: p, requestType: RequestSeat, replyChan: replyChan}

		seatIndex = <-replyChan
		if seatIndex != -1 {
			// ¡Éxito!
			break
		}
		// Si no encontró asiento, espera un poco antes de volver a intentarlo.
		fmt.Printf("❌ %s no encontró asiento, reintentará...\n", p.name)
		time.Sleep(time.Duration(700+rnd.Intn(500)) * time.Millisecond)
	}

	// 3. COMER
	fmt.Printf("✅ %s se sentó y está comiendo en el asiento %d 🍝\n", p.name, seatIndex)
	time.Sleep(time.Duration(1500+rnd.Intn(1000)) * time.Millisecond)

	// 4. LIBERAR ASIENTO
	replyChan := make(chan int)
	requests <- Request{requestType: ReleaseSeat, seatIndex: seatIndex, replyChan: replyChan}
	<-replyChan // Esperar la confirmación del coordinador.

	fmt.Printf("👍 %s terminó y se fue.\n", p.name)
}

func main() {
	// Canal principal de comunicación
	requests := make(chan Request)

	// Pool de filósofos listos para ir a la mesa.
	philosophers := []*Philosopher{
		{name: "Platón"}, {name: "Sócrates"}, {name: "Aristóteles"},
		{name: "Kant"}, {name: "Nietzsche"}, {name: "Descartes"}, {name: "Voltaire"},
	}

	// Iniciar al coordinador en su propia goroutine
	go coordinator(requests, 5) // 5 asientos en la mesa

	var wg sync.WaitGroup
	for _, p := range philosophers {
		wg.Add(1)
		go philosopher(p, requests, &wg)
	}

	// Esperar a que todos los filósofos terminen
	wg.Wait()
	close(requests) // Cerrar el canal para terminar la goroutine del coordinador

	fmt.Println("\nTodos los filósofos han cenado. La cena ha terminado.")
}
