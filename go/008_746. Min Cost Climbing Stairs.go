func minCostClimbingStairs(cost []int) int {
    n := len(cost)
	dp := make([]int, n)
	dp[0] = cost[0]
	dp[1] = cost[1]

	for i := 2; i < len(cost); i++ {
		//min
		if dp[i-2] < dp[i-1] {
			dp[i] = dp[i-2] + cost[i]
		} else {
			dp[i] = dp[i-1] + cost[i]
		}

	}
	if dp[len(cost)-1] < dp[len(cost)-2] {
		return dp[len(cost)-1]
	} else {
		return dp[len(cost)-2]
	}
}