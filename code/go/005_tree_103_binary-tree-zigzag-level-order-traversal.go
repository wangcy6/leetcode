// 01_103.go
package main

func zigzagLevelOrder(root *TreeNode) [][]int {
	var res = [][]int{}
	// 切片slice是引用类型，但是[][]是null时候相当于c++的null指针，只值传递，无法修改指针的本身,
	//解决办法 lambe表达式 Go语言中的闭包同样也会引用到函数外的变量
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, level int) {
		if root == nil {
			return
		}
		// 出现了新的 level
		if level >= len(res) {
			res = append(res, []int{})
		}
		// 与 102 题相比，level 的奇偶不同，append 会不同。
		if level%2 == 0 {
			//追加
			res[level] = append(res[level], root.Val)
		} else {
			temp := make([]int, len(res[level])+1)
			temp[0] = root.Val
			copy(temp[1:], res[level])
			res[level] = temp
		}
		dfs(root.Left, level+1)
		dfs(root.Right, level+1)
	}

	dfs(root, 0)

	return res
}
