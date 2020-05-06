// 329. Longest Increasing Path in a Matrix.go
package main

import "fmt"
import "math"

func max1(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
func longestIncreasingPath(matrix [][]int) int {
	m := len(matrix)
	if m == 0 {
		return 0
	}
	n := len(matrix[0])
	//避免重复计算
	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
		for j := 0; j < n; j++ {
			dp[i][j] = 0
		}
	}

	out := 0

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			//顶点计算过一次不需要重复计算
			if dp[i][j] == 0 {
				//每个顶点最上面一个默认为最小值
				dfs(matrix, dp, math.MinInt64, i, j, m, n)

			}
			out = max1(dp[i][j], out)

		}
	}
	fmt.Println(dp)

	return out

}

func dfs(matrix [][]int, dp [][]int, lastNode int, i int, j int, rows int, cols int) int {
	//位置越界 递归结束
	if i < 0 || i >= rows || j < 0 || j >= cols {
		//fmt.Println("index i=", i, "j=", j)
		return 0
	}
	//不是递增数据，递归结束
	if lastNode >= matrix[i][j] {
		return 0
	}
	//已经计算过，直接返回结果
	if dp[i][j] != 0 {
		return dp[i][j]
	}

	left := 1 + dfs(matrix, dp, matrix[i][j], i-1, j, rows, cols)

	right := 1 + dfs(matrix, dp, matrix[i][j], i+1, j, rows, cols)

	up := 1 + dfs(matrix, dp, matrix[i][j], i, j+1, rows, cols)

	down := 1 + dfs(matrix, dp, matrix[i][j], i, j-1, rows, cols)

	dp[i][j] = max1(max1(left, right), max1(up, down))

	//fmt.Println("i=", i, "j=", j, " set=", dp[i][j], left, right, up, down)

	return dp[i][j]
}
