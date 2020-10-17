package main

import "fmt"

type NullString struct {
	String string
	Valid  bool // Valid is true if String is not NULL
}

func main() {

	//	data := []interface{nil, 0}

	//	if str, ok := data.(string); ok {
	//		/* act on str */
	//		fmt.Println("ok", str)
	//	} else {
	//		/* not string */
	//		fmt.Println("err", str)
	//	}
	input := "helloworld"
	test := NullString{input, true}
	fmt.Println("data", test.String)

}
