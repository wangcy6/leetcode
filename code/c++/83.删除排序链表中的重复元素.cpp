/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (51.37%)
 * Likes:    388
 * Dislikes: 0
 * Total Accepted:    137.5K
 * Total Submissions: 267.7K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        //判断是否相同
        if (head->val == head->next->val) {

            struct ListNode* temp = head;
            head = head->next; //删除只有head的位置。

            temp->next = NULL; //temp 不在是链表中的数据了
            free(temp);

            return deleteDuplicates(head);

        } else {
            // 1 2  3 4
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};
// @lc code=end
