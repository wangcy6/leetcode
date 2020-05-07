// 64.minimum-path-sum.go
package main

import (
	"math"
)

/*
 * @lc app=leetcode.cn id=64 lang=go
 *
 * [64] 最小路径和
 */

// @lc code=start
func minPathSum(grid [][]int) int {
	row := len(grid)
	if row == 0 {
		return 0
	}
	col := len(grid[0])

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if i == 0 && j == 0 {
				continue //第一个记录=最近路径和
			}
			if i == 0 {
				grid[0][j] += grid[0][j-1]
			} else if j == 0 {
				grid[i][0] += grid[i-1][0]
			} else {
				temp := int(math.Min(float64(grid[i][j-1]), float64(grid[i-1][j])))
				grid[i][j] = temp + grid[i][j]
			}

		}
	}
	return grid[row-1][col-1]

}
