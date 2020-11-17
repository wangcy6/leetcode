package main

import (
	"fmt"
)

func printSlice(x []int) {
	fmt.Printf("len=%d cap=%d slice=%v\n", len(x), cap(x), x)
}
func main() {

	array := make([]int, 100)
	for i := 0; i < 100; i++ {
		array[i] = i
	}
	var cursor int = 0
	var numRows int = 80
	left := numRows - cursor
	for i := 0; i < 10; i++ {
		if cursor < numRows {
			printSlice(array[cursor : cursor+left])
			cursor += left
		}

	}
}

/*
len=10 cap=100 slice=[0 1 2 3 4 5 6 7 8 9]
len=10 cap=90 slice=[10 11 12 13 14 15 16 17 18 19]
len=10 cap=80 slice=[20 21 22 23 24 25 26 27 28 29]
len=10 cap=70 slice=[30 31 32 33 34 35 36 37 38 39]
len=10 cap=60 slice=[40 41 42 43 44 45 46 47 48 49]
len=10 cap=50 slice=[50 51 52 53 54 55 56 57 58 59]
len=10 cap=40 slice=[60 61 62 63 64 65 66 67 68 69]
len=10 cap=30 slice=[70 71 72 73 74 75 76 77 78 79]
len=10 cap=20 slice=[80 81 82 83 84 85 86 87 88 89]
len=10 cap=10 slice=[90 91 92 93 94 95 96 97 98 99]*/
