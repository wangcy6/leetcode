// weekly-contest-132.go
package main

/**
01
别人描述的题目是是否理解清楚，如果不知道清楚不是清楚，回答下面2个问题
1 要求获取什么样的结果 清楚吗？
	两个玩家都以最佳状态参与游戏,如果玩家无法执行这些操作，就会输掉游戏，问爱丽丝在游戏中取得胜利？
2 输入什么样的数据清楚吗？
    黑板上有一个数字 N
	0 < x < N
	N % x == 0 。
    N-x
	这是博弈论问题
3 如果还是不清楚，请举例说明，一定不要放过去。
  a 如何表示最佳状态
 一个数字N，能被整除的多个，选择其中一个回赢选择，另外一个会输，
   自然选择赢的那个数字，。只选择能赢的那个数字。

  b 对方赢，自己输 如何表示

**/
func divisorGame(N int) bool {

	dp := make([]bool, N+1)
	dp[0] = false //0 < x < N,不能为为零,无法选择
	dp[1] = false //爱丽丝:0<x<1 无法选择，输掉游戏
	isWin := false

	for i := 2; i <= N; i++ {

		isWin = false
		//爱丽丝 有哪些数字可以选择
		for j := 1; j < i; j++ {
			//爱丽丝 我选择j，
			if i%j == 0 {
				//对方赢，自己输
				isWin = (isWin || !dp[i-j]) //最佳状态
			}
		}
		dp[i] = isWin

	}
	return dp[N]
}

/**
01
别人描述的题目是是否理解清楚，如果不知道清楚不是清楚，回答下面2个问题
1 要求获取什么样的结果 清楚吗？
    求2个节点差值最大：
 	Maximum Difference Between Node and Ancestor
	where V = |A.val - B.val| and A is an ancestor of B

2 输入什么样的数据清楚吗？
  理解1 从root节点到叶子节点 有n个路径，每个路径上m node，n×m个数字差值。


3 真的理解清楚了吗？
   理解纠正 理解1 root节点到child节点n个，每个n也是root节点
   n*m*m 累计差值比较
   The number of nodes in the tree is between 2 and 5000.
Runtime: 88 ms, faster than 5.17% of Go online submissions for Maximum Difference Between Node and Ancestor

time：o(n^2)
space:o(n)

**/
func maxAncestorDiff1(root *TreeNode) int {
	result := 0
	max_diff(root, &result)
	return result
}

func max_diff(root *TreeNode, result *int) {
	if root == nil {
		return
	}
	max_root_diff(root, root.Val, result)

	max_diff(root.Left, result)
	max_diff(root.Right, result)
}

func max_root_diff(root *TreeNode, rootValue int, max *int) {

	if root == nil {
		return
	}
	if *max < root.Val-rootValue {
		*max = (root.Val - rootValue)
	} else if *max < rootValue-root.Val {
		*max = rootValue - root.Val
	}
	max_root_diff(root.Left, rootValue, max)
	max_root_diff(root.Right, rootValue, max)
}

/**
time:0(n)
space:o(n)
通过参数从上到下传递数据 区分什么指针传递，什么使用值传递
这次不是1个参数，是2个参数
Runtime: 4 ms, faster than 96.55%
**/
func maxAncestorDiff(root *TreeNode) int {
	diff := 0
	dFsmaxAncestorDiff(root, root.Val, root.Val, &diff)
	return diff
}

func dFsmaxAncestorDiff(root *TreeNode, min int, max int, diff *int) {
	if root == nil {
		return
	}

	if max < root.Val {
		max = root.Val
	}
	if min > root.Val {
		min = root.Val
	}
	if max-min > *diff {
		*diff = max - min
	}
	dFsmaxAncestorDiff(root.Left, min, max, diff)
	//min, max 不能被先顺遍历节点修改 前面执行 diff 可以
	dFsmaxAncestorDiff(root.Right, min, max, diff)
}

/**
别人描述的题目是是否理解清楚，如果不知道清楚不是清楚，回答下面2个问题
1 要求获取什么样的结果 清楚吗？


2 输入什么样的数据清楚吗？



3 真的理解清楚了吗？
是多少的等差数列
不考虑任何技巧，
时间复杂度：O(n^2 * n) = O(n^3)
空间复杂度：O(1)

第一个数字 和第二个数字比较有个差额，寻找类似的差额 n
第一个数字 和第三个数字比较有个差额，寻找类似的差额 n
第i个数字 。。。。                             n
执行用时：1768 ms

**/
func longestArithSeqLength(A []int) int {
	n := len(A)
	maxLengh := 0
	curLength := 0

	//第一层 每个元素都是序列开始位置
	for i := 0; i < n-1; i++ {

		//第一个元素和j元素寻找差值
		for j := i + 1; j < n; j++ {
			d := A[j] - A[i]
			//寻找类似等差序列
			next := A[j] + d
			curLength = 2
			for k := j + 1; k < n; k++ {
				if A[k] == next {
					curLength++
					next = A[k] + d
				}
			} //3

			if curLength > maxLengh {
				maxLengh = curLength
			}
		} //2
	} //11
	return maxLengh
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
    }
};
