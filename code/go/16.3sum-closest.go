package main

import (
	"math"
	"sort"
)

func threeSumClosest(nums []int, target int) int {

	if len(nums) < 3 {
		return -1
	}
	sort.Ints(nums)

	closest := nums[0] + nums[1] + nums[2] // result

	for i := 0; i < len(nums); i++ {
		start := i + 1
		end := len(nums) - 1
		for start < end {
			sum := nums[i] + nums[start] + nums[end]
			if math.Abs(float64(target)-float64(closest)) > math.Abs(float64(target)-float64(sum)) {
				closest = sum
			}
			if closest == target {
				return closest
			}
			if sum > target {
				end-- //greater then target
			} else {
				start++ //less then target
			}
		}

	}
	return closest

}
