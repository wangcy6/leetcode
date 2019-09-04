// 109.有序链表转换二叉搜索树
package main

/**
convert-sorted-list-to-binary-search-tree/
Given the sorted linked list: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
      0
     / \
   -3   9
   /   /
 -10  5
*/
func sortedListToBST(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}
	lenList := 0
	cur := head

	for cur != nil {
		cur = cur.Next
		lenList++
	}

	return binarySearch(&head, 0, lenList-1)

}

func binarySearch(head **ListNode, start int, end int) *TreeNode {
	if start > end {
		return nil //
	}

	mid := (start + end) / 2
	left := binarySearch(head, start, mid-1)
	root := &TreeNode{(*head).Val, nil, nil}
	root.Left = left
	*head = (*head).Next

	//order must leftSubTree, head ,rightSubTree
	right := binarySearch(head, mid+1, end)
	root.Right = right

	return root
}
