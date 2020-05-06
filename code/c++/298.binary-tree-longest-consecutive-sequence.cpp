#知识卡
### 题目
[LeetCode] Binary Tree Longest Consecutive Sequence 二叉树最长连续序列

Given a binary tree, find the length of the longest consecutive sequence path.
The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The longest consecutive path need to be from parent to child (cannot be the reverse).
For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.

   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

 //https://leetcode.com/problems/longest-consecutive-sequence/

### 理解

- consecutive sequence path:是递增序列，每次递增的step=1
-longest consecutive sequence path 最长的，每个节点都需要比较一次
- 类似求tree的高度从下到上的返回结果也可以。
- 还有一个方面从上到下传递数据。利用值传递方式，实现求左右子树最大的path


复杂度

时间O(n)

### 代码
~~~
int longestConsecutive(Node* root) 
{ 
    if (root == NULL) 
        return 0; 
  
    int res = 0; 
  
    longestConsecutiveUtil(root, 0, root->data, res); 
  
    return res; 
} 


void longestConsecutiveUtil(Node* root, int curLength, 
                              int &expected, int& res) 
{ 
    if (root == NULL) 
        return; 

    if (root->data == (expected+1)) 
        curLength++; 
    else
        curLength = 1; 
  

    res = max(res, curLength); 
  
    longestConsecutiveUtil(root->left, curLength, 
                           root->data , res); 
    longestConsecutiveUtil(root->right, curLength, 
                           root->data , res); 
} 
  

~~~

