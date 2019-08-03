/**
 * https://leetcode-cn.com/problems/partition-list/
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       
       if(head ==NULL ||head->next==NULL)
       {
           return head;
       }
       
       //分割成2个链表的范围
       ListNode* head1=NULL;
       ListNode* small=NULL;
       
       ListNode* big=NULL;
       ListNode* head2=NULL;
       
       while(head)
       {
           if(head->val<x)
           {
              if(small ==NULL)
              {  
                head1=head;
                small=head;
              }else
              {
                  small->next=head;
                  small=head;//
              }
           }else
           {
              if(big ==NULL)
              {  
                head2=head;
                big=head;
              }else
              {
                  big->next=head;
                  big=head;//
              }
           }

           head=head->next;//遍历过程中，head本身没有发生变化 ，对比翻转链表。
       }
       //优化 头节点 不用判断small null还是非null
       if(small ==NULL)
       {
          head1=head2;
       }else
       {
           small->next=head2;
       }
       if(big)
       {
         big->next=NULL;
       }
       

       return head1;
    }
};