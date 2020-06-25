/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        //构造带头节点单链表，为什么一定用带头节属于个人习惯。
        ListNode out(-1);
        ListNode *ptr = &out;
        //小根堆
        auto cmp = [](const ListNode *a, ListNode *b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> priorityQueue(cmp);
        //priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> priorityQueue(cmp);

        //比较K个排序链表第一个元素
        for (auto head : lists)
        {   
            if(head)
            {
              priorityQueue.push(head);
            }
            
        }

        //只要获取head节点，就能获取整个链表，因此后面不需要lists

        while (priorityQueue.empty() ==false)
        {
            ListNode * ptemp =priorityQueue.top();
            priorityQueue.pop();//移走最小元素
            if(ptemp->next)
            {
              priorityQueue.push(ptemp->next);
            }

            //构造链表

            ptr->next =ptemp;
            ptr=ptemp;

        }

        return out.next;
    }
};
// @lc code=end
