package main

import "fmt"

func main() {

	data := []interface{nil, 0}

	if str, ok := data.(string); ok {
		/* act on str */
		fmt.Println("ok", str)
	} else {
		/* not string */
		fmt.Println("err", str)
	}

}
