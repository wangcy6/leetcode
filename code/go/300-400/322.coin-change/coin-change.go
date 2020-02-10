// coin-change.go
package main

import (
	"fmt"
)

func coinChange(coins []int, amount int) int {

	return coinChangeNode(0, coins, amount)

}

func coinChangeNode(index int, coins []int, amount int) {

}
func main() {

	data := []int{1}

	fmt.Println(coinChange(data, 2))
}
