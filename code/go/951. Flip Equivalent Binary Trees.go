// 951. Flip Equivalent Binary Trees.go
package main

/**
01
别人描述的题目是是否理解清楚，如果不知道清楚不是清楚，回答下面2个问题
1 要求获取什么样的结果 清楚吗？
	只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 false
2 输入什么样的数据清楚吗？
	爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。

	最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：

	选出任一 x，满足 0 < x < N 且 N % x == 0 。
	用 N - x 替换黑板上的数字 N 。
	如果玩家无法执行这些操作，就会输掉游戏。

3 如果还是不清楚，请举例说明，一定不要放过去。





**/
func flipEquiv(root1 *TreeNode, root2 *TreeNode) bool {
	if root1 == nil && root2 == nil {
		return true
	}

	if root1 == nil || root2 == nil || root1.Val != root2.Val {
		return false
	}
	//递归指的是一种通过重复将问题分解为同类的子问题而解决问题的方法 分解为子问题
	return flipEquiv(root1.Left, root2.Right) && flipEquiv(root1.Right, root2.Left) || flipEquiv(root1.Left, root2.Left) && flipEquiv(root1.Right, root2.Right)
}
