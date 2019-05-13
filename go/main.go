package main

import "fmt"

func main() {

	//data := []int{9, 7, 6, 5, 1, 2, 3, 4, 4, 4, 4}
	//fmt.Println(findMinData(data))
	//fmt.Println(divisorGame(6))

	root := InitTreeByInput()
	fmt.Println(maxAncestorDiff(root))

}
