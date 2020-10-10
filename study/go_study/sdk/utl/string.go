package main

import (
	"fmt"
	"strings"
	"unicode/utf8"
)

func main() {
	var name = "q``q"
	var name1 = `index_     `
	var name2 = "q''q"
	if name == name2 {
		fmt.Println("===============")
	} else {
		fmt.Println("not euql ")
	}

	if len(name) == 0 && name == `` {
		fmt.Println("33Incorrect index name ", name)
	}
	if len(name) == 0 && name == "" {
		fmt.Println("44 Incorrect index name2 ", name2)
	}
	if len(name1) > 0 && strings.Contains(name1, "") {
		fmt.Println("Incorrect index name1 ", name1)
	}
	if len(name2) == 0 && name2 == "" {
		fmt.Println("11Incorrect index name2 ", name2)
	}
	if len(name2) == 0 && name2 == `` {
		fmt.Println("22Incorrect index name2 ", name2)
	}
	//	fmt.Println("go" == "go")
	//	fmt.Println("GO" == "go")

	fmt.Println(strings.Compare(name, ``))
	//	fmt.Println(strings.Compare("go", "go"))

	//	fmt.Println(strings.EqualFold("GO", "go"))
	str := `Hello World! \n Hello Gopher! \n`
	fmt.Println(str)
	str1 := "Hello World! \n Hello Gopher! \n"
	fmt.Println(str1)
	s := "其实就是rune"
	fmt.Println(len(s))                    // "16"
	fmt.Println(utf8.RuneCountInString(s)) // "8"

	s1 := "Go语言四十二章经"
	for k, v := range s1 {
		fmt.Printf("k：%d,v：%c == %d\n", k, v, v)
	}
}

//https://wizardforcel.gitbooks.io/go42/content/content/42_10_string.html
