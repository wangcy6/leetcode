// 997_find-the-town-judge.go
package main

/**
993. 二叉树的堂兄弟节点
如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点
儿子不是
儿子的儿子才是
目的：求节点<x,y>深度和parent节点
过程：递归遍历 dfs
time:o(n)
space:o(n)
**/
func isCousins(root *TreeNode, x int, y int) bool {

	var px *TreeNode = nil
	var py *TreeNode = nil
	var dx int = 0
	var dy int = 0
	//值在函数体内被修改
	is_cousins(root, x, y, 1, root, &px, &py, &dx, &dy)
	//如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点

	return dx == dy && px != py

}
func is_cousins(root *TreeNode, x int, y int, level int, parent *TreeNode, px **TreeNode, py **TreeNode, dx *int, dy *int) {
	if root == nil {
		return
	}
	if root.Val == x {
		*dx = level
		*px = parent

	}
	if root.Val == y {
		*dy = level
		*py = parent
	}

	is_cousins(root.Left, x, y, level+1, root, px, py, dx, dy)
	is_cousins(root.Right, x, y, level+1, root, px, py, dx, dy)
}

/**
994. 腐烂的橘子
rotting-oranges
https://leetcode-cn.com/contest/weekly-contest-124/problems/rotting-oranges/
https://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/

题目理解：
1. 腐烂的橘子不知道在哪来，
2 腐烂的橘子有多少个，但是给的例子都是1个，可能有很多很多
3， 最小分钟数 为什么会有最小，可能有很多很多
4 DFS 递归遍历
业务逻辑
1 good -bad -again
2 bad -ok
3 nothing -ok
Solution: BFS
Time complexity: O(mn)
Space complexity: O(mn
**/
func orangesRotting(grid [][]int) int {
	row, col := len(grid), len(grid[0])
	var rottenOranges [][]int
	//01 寻找腐烂的橘子
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if grid[i][j] == 2 {
				rottenOranges = append(rottenOranges, []int{i, j})
			}
		}
	}

	var rotNum, times int
	//bfs 遍历
	for {
		rotNum = 0
		length := len(rottenOranges)
		var tmp [][]int
		for i := 0; i < length; i++ {
			x, y := rottenOranges[i][0], rottenOranges[i][1]
			for _, p := range [][]int{{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}} {
				if p[0] < 0 || p[0] >= row || p[1] < 0 || p[1] >= col {
					continue
				}
				if grid[p[0]][p[1]] == 1 {
					grid[p[0]][p[1]] = 2
					rotNum++
					tmp = append(tmp, []int{p[0], p[1]})
				}
			}
		}
		//无法感染，或者已经感染完毕
		if rotNum == 0 {
			break
		}
		times++
		rottenOranges = tmp
	}
	//03 验证
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if grid[i][j] == 1 {
				return -1
			}
		}
	}

	return times
}

//假设不对， 边界条件太复杂了
func orangesRotting_err(grid [][]int) int {
	row, col := len(grid), len(grid[0])

	times := 0

	//01 寻找腐烂的橘子
	x := -1
	y := -1
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if grid[i][j] == 2 {
				x = i
				y = j
				break //only one
			}
		}
	}

	//02 遍历

	orages_rotting(grid, row, col, x+1, y, 0, &times)
	orages_rotting(grid, row, col, x-1, y, 0, &times)
	orages_rotting(grid, row, col, x, y+1, 0, &times)
	orages_rotting(grid, row, col, x, y-1, 0, &times)

	//03 验证

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {

			if grid[i][j] == 1 {
				return -1
			}
		}
	}

	return times
}

//遍历二位结构
func orages_rotting(grid [][]int, row int, col int, x int, y int, level int, times *int) {

	if x < 0 || y < 0 || x >= row || y >= col {

		return
	} //递归结束条件
	//无法感染，或者已经感染完毕 ,第一个入口是腐烂的如何排除
	if grid[x][y] == 0 || grid[x][y] == 2 {

		return
	}
	grid[x][y] = 2

	if *times < level {
		*times = level
	}
	//同一层
	orages_rotting(grid, row, col, x+1, y, level+1, times)
	orages_rotting(grid, row, col, x-1, y, level+1, times)
	orages_rotting(grid, row, col, x, y+1, level+1, times)
	orages_rotting(grid, row, col, x, y-1, level+1, times)

}

/**

题目理解了吗，
如果你理解了，你清楚知道 条件和求结果是什么
如果3秒内无法说出，说明 根本没理解。

理解1 如果节点的深度为 D，则其直接子节点的深度为 D + 1。
理解2 如果节点只有一个子节点，那么保证该子节点为左子节点
We need to remember two things.
Since it is preoder, left comes before right
Assumption is if there is only one child, it has to be a left child.


func recoverFromPreorder(S string) *TreeNode {
	i := 0
	return recover_from_string(&s, &i, 0)
}
**/
//
/**
func recover_from_string(input *string, index *int, depth int) *TreeNode {

	//当前元素的高度
	realDeth := get_node_depth(s,index)
	//判断当前元素是上个元素子元素
	if depth != realDeth {
		 *index-=realDeth //index全局变量 要回退，不正确的位置
		retur nil
	}
	//字符串变整数
	nodeValue:=get_node_value(s,index)

	ptr:=new TreeNode(nodeValue,nil,nil);
	ptr.Left=recover_from_string(s,index,depth+1)
	ptr.Right=recover_from_string(s,index,depth+1)
	return ptr
}

func get_node_depth(s *string,index* int){
	 d:=0
	for ;*index<len(s)&&s[*index]!='-';*index++{
		d++
	}
	return d
}
func get_node_value(s *string,index* int){
	 val:=0
	for ;*index<len(s)&&s[*index]!='-';*index++{
		val=val*10+(s[*index]='0')
	}
	return val
}
**/
