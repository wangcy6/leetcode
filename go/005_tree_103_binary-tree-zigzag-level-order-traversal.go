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

<<<<<<< HEAD
//闭包https://blog.csdn.net/wangshubo1989/article/details/79217291
//lambda本质就是一个匿名函数 https://blog.csdn.net/u010386612/article/details/79875303
func test() {
	x, y := 1, 2
	//defer 中使用匿名函数依然是一个闭包
	defer func(a int) {
		fmt.Printf("x:%d,y:%d\n", a, y) // y 为闭包引用
		//Go语言中的闭包同样也会引用到函数外的变量
	}(x) // 复制 x 的值

	x += 100
	y += 100
	fmt.Println(x, y)
}

=======
>>>>>>> bad9cf0241eaa9dfdde9f837a3bf63b93451ab40
/**
func main() {

	treeNode := InitTreeByInput()
	fmt.Println(zigzagLevelOrder(treeNode))
<<<<<<< HEAD
	test()
=======

>>>>>>> bad9cf0241eaa9dfdde9f837a3bf63b93451ab40
}**/
