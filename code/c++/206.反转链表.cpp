/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    //描述：利用递归，从右到左的反转。 
    // 4-->5  5-->4->nill 
    ListNode* reverseList1(ListNode* head) {

        if(head ==NULL || head->next ==NULL)
        {
            return head;
        }

        ListNode* end =reverseList(head->next);
  
        head->next->next =head;// 5-->4, 1->2->3->4
        head->next=NULL;

        return end;

    }
    //经典的：固定的头节点位置插入 一个元素 o(1)
    //反转链表
    ListNode* reverseList(ListNode* head) {

        ListNode root(-1);
        root.next =head;//root->next 含义是链表第一个元素
        
        //退出条件：最后一个元素 
        while(head && head->next)
        { 
            // head ->1--2--3--4--5
           ListNode* ptemp=head->next;//
           head->next =ptemp->next; // step
          
           ptemp->next =root.next; ///insert
           root.next=ptemp;

        }
        return  root.next;

    }
};
// @lc code=end

