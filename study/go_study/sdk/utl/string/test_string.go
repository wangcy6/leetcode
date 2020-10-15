package main

import "fmt"

func main() {
	//var name string = nil
	//fmt.Println(name)
	var data interface{}
	data = nil

	if str, ok := data.(string); ok {
		/* act on str */
		fmt.Println("ok", str)
	} else {
		/* not string */
		fmt.Println("err", str)
	}

}
