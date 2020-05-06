package main

import (
	"fmt"
	"time"
)

var x, y int

func test2() {

	go func() {
		x = 1
		fmt.Println("1 y = ", x, y)
	}()
	go func() {
		y = 1
		fmt.Println("2 x = ", x, y)
	}()
	time.Sleep(time.Second)
}

func main() {
	test2()
}
