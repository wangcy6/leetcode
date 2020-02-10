// coin-change.go
package main

import (
	"fmt"
	"sort"
	"time"
)

/**
执行用时 :
8 ms, 在所有 Go 提交中击败了97.33%的用户
内存消耗 :2.1 MB, 在所有 Go 提交中击败了100.00%的用户
**/
func coinChange(coins []int, amount int) int {
	var lessTotal int = 99999
	sort.Sort(sort.Reverse(sort.IntSlice(coins))) //大到到下
	fmt.Println(coins)

	coinChange2(0, coins, amount, 0, &lessTotal)
	if lessTotal == 99999 {
		lessTotal = -1 //零钱无法找零
	}
	return lessTotal

}

func coinChange2(index int, coins []int, amount int, sum int, lessTotal *int) {

	//走到最低了
	if amount == 0 {
		if sum < *lessTotal {
			*lessTotal = sum
		}
	}
	if amount < 0 {
		return //该组合无法成立
	}
	//相当于一层循环
	if index >= len(coins) {
		return //amount 组合不成立
	}
	count := amount / coins[index] //最多多少个该金币组成
	//从最大开始尝试,最少i是0， amount-i*coins[index]数值保持不变
	//如果当前组合超过最小值，后面的递归就不需要判断
	for i := count; i >= 0 && sum+i < *lessTotal; i-- {
		coinChange2(index+1, coins, amount-i*coins[index], sum+i, lessTotal)
	}
}

/**
* [3,7,405,436] 8839 百万级别
**/
func coinChange1(coins []int, amount int) int {

	return coinChangeNode(0, coins, amount)

}

func coinChangeNode(index int, coins []int, amount int) int {
	fmt.Println("coinChangeNode")

	if amount == 0 {
		//总金额amount可以被硬币组合
		return 0
	}
	if index >= len(coins) {
		return -1
	}
	if amount < 0 {
		return -1 // 无法有该硬币构成
	}

	maxCount := amount / coins[index]
	fmt.Println("maxCount", maxCount)
	var total int = 999999
	//缺点 我不能区分那个最少，最正确，暴力破解，all情况必须尝试一遍。
	//每个情况都要尝试一次，全部的都要尝。
	//这就是优化地方

	for i := 0; i <= maxCount; i++ {

		left := amount - i*coins[index]
		count := coinChangeNode(index+1, coins, left)

		if count == -1 {
			continue
		}
		count += i
		if count < total {
			total = count
		}

	}
	if total == 999999 {
		total = -1 //后面的失败，前面的
	}
	return total
}
func main() {

	//data := []int{1}

	//data := []int{3, 7, 405, 436}
	startT := time.Now() //计算当前时间
	//fmt.Println(coinChange(data, 2)) //window 系统直接卡死

	//fmt.Println(coinChange(data, 8839)) //window 系统直接卡死

	data := []int{2}
	fmt.Println(coinChange(data, 3)) //-1
	tc := time.Since(startT)         //计算耗时
	fmt.Printf("time cost = %v\n", tc)
}
