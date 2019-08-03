package main

import "fmt"

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {

	//data := []int{9, 7, 6, 5, 1, 2, 3, 4, 4, 4, 4}
	//fmt.Println(findMinData(data))
	//fmt.Println(divisorGame(6))

	//tree
	//root := InitTreeByInput()
	//fmt.Println(maxAncestorDiff(root))

	//two array
	/**
	data1 := [][]int{
		{3, 4, 5},
		{3, 2, 6},
		{2, 2, 1}}
	/**
	data2 := [][]int{
		{1, 2, 3}}**/

	data3 := [][]int{
		{7, 7, 5},
		{2, 4, 6},
		{8, 2, 0}}
	fmt.Println("longestIncreasingPath=", longestIncreasingPath(data3))

}
