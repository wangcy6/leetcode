
/** 148
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 https://leetcode.com/problems/sort-list/
 输入: 4->2->1->3
 输出: 1->2->3->4
 */
class Solution {
public:

    //直接插入排序，链表翻转的升级版
    ListNode* sortList_insert(ListNode* head) 
    {
          if ( head == NULL) return head;
          //有序链表第一节点默认为head
          ListNode* start=NULL;
          ListNode* end=head;

          ListNode dump(-1);
          dump.next=head;
          start=&dump; //head->next代表含义 和stat->next代表含义不一样

          ListNode* cur=NULL;
          ListNode* temp=NULL;
          
          while (end && end->next)
          {
              if (end->next->val > end->val)
              {
                  end=end->next;//升序
                  continue;
              }
              //寻找位置
             temp=end->next;
             end->next =end->next->next;//修改end.next位置
          
            for (cur=start;cur->next->val<temp->val;cur=cur->next)
            {
               
            }

            //插入
            temp->next=cur->next;
            cur->next=temp;

          }

          return dump.next;

    }
};