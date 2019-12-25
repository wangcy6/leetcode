package main

import "sort"
import "fmt"

//39. 组合总和 回溯算法 golang
//https://leetcode-cn.com/problems/combination-sum/solution/golang-dpsuan-fa-chao-guo-9275-by-jhzhu89/
func combinationSum(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	var res = [][]int{} //不确定大小
	var path = []int{}  //不确定大小
	dfs := func(candidates []int, sum int, target int, start int) {}

	dfs = func(candidates []int, sum int, target int, start int) {
		if sum > target {
			return //递归结束 累加不符合
		}
		if sum == target {
			cp := make([]int, len(path))
			copy(cp, path)
			res = append(res, cp) //这个方法最后不正确了
			//fmt.Println("sum == target")
			//PrintArray(path)
			return //递归结束  find

		}
		m := len(candidates)
		//每次都有n-start个选择
		for i := start; i < m; i++ {
			temp := sum + candidates[i]
			if temp > target {
				break
			}
			path = append(path, candidates[i]) //append用来将元素添加到切片末尾并返回结果。
			//PrintArray(path)
			dfs(candidates, temp, target, i)

			path = path[:len(path)-1]
			//PrintArray(path)
		}

	}
	dfs(candidates, 0, target, 0)

	return res

}
func main() {
	candidates := []int{2, 3, 6, 7}
	res := combinationSum(candidates, 7)
	fmt.Println("--------------")
	PrintArray2(res)
}
