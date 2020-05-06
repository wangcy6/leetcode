// 141. Linked List Cycle.go
package main

/**
01
别人描述的题目是是否理解清楚，如果不知道清楚不是清楚，回答下面2个问题
1 要求获取什么样的结果 清楚吗？
	给定一个链表，判断链表中是否有环。
2 输入什么样的数据清楚吗？
	可能有，也可能没有

3 如果还是不清楚，请举例说明，一定不要放过去。

   你理解还是偏差：择任意节点 是0个，1个，还是全部呢。


 complexity is O(N+K)
**/
func hasCycle(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return false
	}

	slow := head
	fast := head.Next

	for slow != fast {
		if fast == nil || fast.Next == nil {
			return false
		}

		slow = slow.Next
		fast = fast.Next.Next

	}
	return true

}
