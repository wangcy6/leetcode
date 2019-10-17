package main

import "math"

/**


1 直觉
2 想法
3 算法
4 复杂度

64. Minimum Path Sum
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

时间复杂度 O(M×N) ： 遍历整个 gridgrid 矩阵元素。
空间复杂度 O(1)O(1) ： 直接修改原矩阵，不使用额外空间


**/
func minPathSum(grid [][]int) int {

	rows := len(grid)
	if rows == 0 {
		return 0
	}
	cols := len(grid[0])

	//1 状态定义:设 dp(grid) 为大小  nm×n 矩阵，其中 dp[i][j] 的值代表直到走到 (i,j) 的最小路径和
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {

			if i == 0 && j == 0 {
				continue //3 初始状态
			}
			//2 转移方程
			if i == 0 {
				grid[i][j] = grid[i][j-1] + grid[i][j]
			} else if j == 0 {
				grid[i][j] = grid[i-1][j] + grid[i][j]
			} else {
				temp := int(math.Min(float64(grid[i][j-1]), float64(grid[i-1][j])))
				grid[i][j] = temp + grid[i][j]
			}

		}
	}
	//4 返回值
	return grid[rows-1][cols-1]

}
