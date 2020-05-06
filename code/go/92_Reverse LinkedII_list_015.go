package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {

	if head == nil || m >= n {
		return head
	}

	var dump ListNode
	dump.Next = head
	start := &dump //不区分m=1 还是非1

	for i := 1; i < m; i++ {
		start = start.Next // 移动m-个位置
	}

	end := start.Next

	//n-m-1 记录
	for i := m; i < n; i++ {

		cur := end.Next
		end.Next = end.Next.Next

		cur.Next = start.Next
		start.Next = cur

	}

	return dump.Next

}
