/*
 * @lc app=leetcode.cn id=300 lang=golang
 *
 * [300] 最长上升子序列
 */

// @lc code=start

//超出时间限制
func lengthOfLIS(nums []int) int {
  var dp [][]int

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
		// [1,2 ,3 ,4 ,5 ,6 ,7]
		lenUsed = 1 + helperBack(nums, nums[index], index+1)
	}
	//[8,7,6,5,4,3,2,1]
	lenNoUsed := helperBack(nums, pre, index+1)
	if lenUsed > lenNoUsed {
		return lenUsed
	}
	return lenNoUsed
}

// @lc code=end
