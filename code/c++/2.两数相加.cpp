/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
     //两数相加 
     //思路：while 遍历链表 ，变量是如何变化的 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
     ListNode  head(0);// 
     ListNode* ptr =&head;//
     int result =0;//加法运算的结果
  
     while(l1 !=NULL  || l2 !=NULL || result >0)
     {
         if (l1) //长度不一，有可能为null
         {
             result+=l1->val;
             l1=l1->next; //move
         }

         if (l2) //长度不一，有可能为null
         {
             result+=l2->val;
             l2=l2->next; //move
         }

         ptr->next =new ListNode(result%10);
         ptr =ptr->next; //move

         result/=10;
     }
     
     return head.next;

    }
};
// @lc code=end

