// 46.permutations.go
package main

import (
	"fmt"
)

//https://leetcode.com/problems/permutations/discuss/309263/Go-for-short
/* https://leetcode-cn.com/problems/permutations/
*https://leetcode.com/problems/permutations/discuss/277169/my-go-solution-backtracking
  2 step

* 3 test
* out =nil
*/
func permute(nums []int) [][]int {
	length := len(nums)
	if 0 == length {
		return nil
	}
	out := [][]int{}
	used := make([]bool, length)
	for i := 0; i < length; i++ {
		used[i] = false
	}
	path := []int{}
	BackTrace(nums, used, &path, 0, &out)
	return out
}
func BackTrace(nums []int, used []bool, path *[]int, start int, out *[][]int) {
	if start == len(nums) {
		temp := make([]int, len(*path))
		copy(temp, *path)
		*out = append(*out, temp)
		return
	}
	for i := 0; i < len(nums); i++ {
		if used[i] == true {
			continue
		}
		used[i] = true
		//path[i] = nums[i]
		*path = append(*path, nums[i])
		BackTrace(nums, used, path, start+1, out)
		//path[i] = 0
		*path = (*path)[:len(*path)-1]
		used[i] = false
	}

}
func main() {
	fmt.Println("Hello World!")
}
