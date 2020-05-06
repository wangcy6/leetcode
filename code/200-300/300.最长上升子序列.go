package main

import (
	"fmt"
)

/*
 * @lc app=leetcode.cn id=300 lang=golang
 *
 * [300] 最长上升子序列
 */

// @lc code=start

func lengthOfLIS(nums []int) int {
	length := len(nums)
	//var dp [length][length]int
	dp := make([][]int, length) //subString[start,end]
	for i := 0; i < length; i++ {
		dp[i] = make([]int, length)
	}
	begin := 0
	pre := begin - 1
	return backTraceLIS(nums, pre, begin, dp)

}

func backTraceLIS(nums []int, lastStart int, start int, dp [][]int) int {
	if start == len(nums) {
		return 0 //没有元素了
	}
	if dp[lastStart+1][start] > 0 {
		return dp[lastStart+1][start]
	}

	lenUsed := 0
	if lastStart < 0 || nums[start] > nums[lastStart] {
		lenUsed = 1 + backTraceLIS(nums, start, start+1, dp)

	}
	lenNoUsed := backTraceLIS(nums, lastStart, start+1, dp)

	if lenUsed > lenNoUsed {
		dp[lastStart+1][start] = lenUsed
	} else {
		dp[lastStart+1][start] = lenNoUsed
	}
	return dp[lastStart+1][start]

}

func lengthOfLIS1(nums []int) int {

	return helperBack(nums, -10000, 0)

}

func helperBack(nums []int, pre int, index int) int {
	if index == len(nums) {
		return 0
	}
	lenUsed := 0
	if nums[index] > pre {
		// [1,2 ,3 ,4 ,5 ,6 ,7]index
		lenUsed = 1 + helperBack(nums, nums[], index+1)
	}
	//[8,7,6,5,4,3,2,1]
	lenNoUsed := helperBack(nums, pre, index+1)
	if lenUsed > lenNoUsed {
		return lenUsed
	}
	return lenNoUsed
}

// @lc code=end
func main() {

	//array := []int{1, 2, 3, 4, 5, 6}
	array := []int{6, 5, 4, 3, 2, 1}
	fmt.Println(lengthOfLIS(array))
	fmt.Println(lengthOfLIS1(array))

}
