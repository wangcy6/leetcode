/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 *
 https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (69.00%)
 * Likes:    116
 * Dislikes: 0
 * Total Accepted:    13.7K
 * Total Submissions: 19.9K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 *
 *
 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 
 
 
 
 
 
 
 *
 *
 *

 *
 * 示例:
 *
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 *
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索
 
 
 
 
 
 
 
 *  ：
 *
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 *
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };//https://www.youtube.com/watch?v=SS5Td7iz_0k
 */
class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (NULL == head)
      return NULL;
    int listSize = 0;
    ListNode *ptr = head;
    while (ptr != NULL) {
      ptr = ptr->next;
      listSize++;
    }

    return dfs(head, 0, listSize - 1);
  }
  TreeNode *dfs(ListNode *&head, int start, int end) {
    if (start > end)
      return NULL;
    int mid = (start + end) / 2; // why??

    TreeNode *pRoot = new TreeNode(head->val);
    TreeNode *pLeft = dfs(head, start, mid - 1);
    // pRoot->left = pLeft;

    head = head->next; // why

    TreeNode *pRight = dfs(head, mid + 1, end);
    pRoot->left = pLeft;
    pRoot->right = pRight;
    return pRoot;
  }
};
// @lc code=end
// https://www.cnblogs.com/grandyang/p/9615871.html
//[LeetCode] 426. Convert Binary Search Tree to Sorted Doubly Linked List
//将二叉搜索树转为有序双向链表
