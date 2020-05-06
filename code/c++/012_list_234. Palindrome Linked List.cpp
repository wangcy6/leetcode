#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std; 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
1  定义2个指针，head tail 
2. 递归遍历tail链表
3. 通过
     head++  链表前进, 递归特点:从上到下 
             这个是子递归完在函数内部修改的，然后当前递归在使用
             head已经发生改变）
     tail --     链表倒退,  
                 递归特点 回溯，利用函数栈跟踪轨获取最后节点。
                 tail没有改变
   判断是否回文 tail ==head
4.如果是继续，如果不是返回false
**/
/**
https://leetcode-cn.com/problems/palindrome-linked-list/
Input: 1->2->2->1
Output: true
Could you do it in O(n) time and O(1) space?
**/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        return isPalindrome(head,head);
    }
    //bool isPalindrome(ListNode* tail,ListNode* head)
    bool isPalindrome(ListNode* tail,ListNode* &head)
    {
        if(NULL==tail) 
        {
            return true;
        }
        // 1->2->2->1
        bool flag=isPalindrome(tail->next,head);
        if (false ==flag)
        {
            return false;
            
        }
        
        if (tail->val !=head->val)
        {
            return false;
        }
        head =head->next;//
		
        return true;
        
    }
};