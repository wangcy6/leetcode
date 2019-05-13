package main

import "fmt"

func decorator(f func(s string)) func(s string) {
	return func(s string) {
		fmt.Println("Started")
		f(s)
		fmt.Println("Done")
	}
}

func Hello(s string) {
	fmt.Println(s)
}

type Widget struct {
	X, Y int
}

type Label struct {
	Widget        // Embedding (delegation)
	Text   string // Aggregation
	X      int    // Override
}

func (label Label) Paint() {
	// [0xc4200141e0] - Label.Paint("State")
	fmt.Printf("[%p] - Label.Paint(%q)\n",
		&label, label.Text)
}

func main() {
	decorator(Hello)("Hello, World!")
}
