package main

import "fmt"

func rightSideView(root *TreeNode) []int {

	result := make([]int, 0) //创建切片,长度为0,容量为0
	dfs(root, 0, &result)
	return result
}

func dfs(root *TreeNode, level int, result *[]int) {

	if root == nil {
		return
	}
	//指针切片,在长度为i基础上追加一个元素。
	if len(*result) == level {
		*result = append(*result, root.Val)
	}
	dfs(root.Right, level+1, result)
	dfs(root.Left, level+1, result)
}

func main() {

	data := make([]int, 5, 10)
	fmt.Println(len(data), cap(data))
	data[3] = 4

}

//stl
// 原因append总是在当前slice的最后添加元素，当我们用 var s = make([]string, 10)
// 初始化s的时候，就已经为s创建了10个元素，每一个元素的值都是空串，调用append函数的时候会发现此时s已经有10个元素了，
// 所有"aaa"会被添加进第11个元素。
//https://blog.csdn.net/andylanzhiyong/article/details/88654237?utm_medium=distribute.pc_relevant.none-task-blog-baidujs-2
