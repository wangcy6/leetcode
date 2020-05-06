// 72.edit-distance
package main

func minDistance(word1 string, word2 string) int {

	n := len(word1)
	m := len(word2)
	dp := make([][]int, n+1) // 定义 dp[i][j] 是字符串 word1[0..i - 1] 到 word2[0..j - 1] 最小编辑距离
	for i := range dp {
		dp[i] = make([]int, m+1)
	}
	// 默认值
	for i := 0; i <= n; i++ {
		dp[i][0] = i
	}
	for j := 0; j <= m; j++ {
		dp[0][j] = j
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if word1[i-1] == word2[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))
				//其中，dp[i-1][j-1] 表示替换操作，dp[i-1][j] 表示删除操作，dp[i][j-1] 表示插入操作
			}

		}
	}
	return dp[n][m]
}
