/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (57.97%)
 * Likes:    272
 * Dislikes: 0
 * Total Accepted:    24.9K
 * Total Submissions: 42.2K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 二叉搜索树中的两个节点被错误地交换。
 * 
 * 请在不改变其结构的情况下，恢复这棵树。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * 输出: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * 示例 2:
 * 
 
 * // 【1  2  3  4 】 (2,3)
 * // 【1  3  2  4 】  只有3>2 ,没有第二个比较， 该怎么办 （first>second）
 * 进阶:
 * 
 * 
 * 使用 O(n) 空间复杂度的解法很容易实现。
 * 你能想出一个只使用常数空间的解决方案吗？
 * 
 *  第一次：被hard基本题目吓住了：
 *  第二次：搜索tree 常用做法就是递归遍历 输出顺序是升序
 *   排序，重组 还是看不出来
 *  第三次：
 * 我们来看下如果在一个递增的序列中交换两个值会造成什么影响。
 * 假设有一个递增序列 a=[1,2,3,4,5,6,7] 
 * 。如果我们交换两个不相邻的数字，例如 2 和 6，
 * 原序列变成了 a=[1,6,3,4,5,2,7]，
 *  6>3，5>2


​	
。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/recover-binary-search-tree/solution/hui-fu-er-cha-sou-suo-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * 
 *   
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution1 {
public:
    // 52ms
    void recoverTree(TreeNode* root)
    {
        // 01 check
        if (root == NULL) {
            return;
        }
        // 02 dfs
        TreeNode* first = NULL; //第一个元素 6>3，选择 6  【1 2 3 4 5 6】（6,2）
        TreeNode* second = NULL; // 第二个元素 5>2 选择 2 【1 2 3 4 5 6】（6,2）
        TreeNode* pre = NULL; // 记录上一个记录
        recoverTree(root, pre, first, second);

        //03 swap
        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }

    void recoverTree(TreeNode* root, TreeNode*& pre, TreeNode*& first, TreeNode*& second)
    {
        if (NULL == root) {
            return; //递归退出条件
        }
        //01 中序递归遍历
        recoverTree(root->left, pre, first, second);

        //here
        //判断是否逆序
        if (pre && pre->val > root->val) {
            if (first == NULL) {
                first = pre; //must
                second = root;
                // 【1  2  3  4 】 (2,3)
                // 【1  3  2  4 】  只有3>2 ,没有第二个比较， 该怎么办 （first>second）
            } else {
                second = root;

                // *假设有一个递增序列 a = [ 1, 2, 3, 4, 5, 6, 7 ]
                //  如果我们交换两个不相邻的数字，例如 2 和 6，
                // 原序列变成了 a = [ 1, 6, 3, 4, 5, 2, 7 ] ，
                //   first 6 > 3， second）5 > 2
            }
        }

        //记录
        pre = root;
        recoverTree(root->right, pre, first, second);
    }
};

class Solution {
public:
    //32ms
    void recoverTree(TreeNode* root)
    {

        //01 check
        if (nullptr == root)
            return;

        //02 依赖stack
        //非递归遍历,在一个函数内完成，不需要二级指针传递参数.保存改变
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* pre = nullptr;
        vector<TreeNode*> stack; //用数组模拟栈
        //stack.push_back(root); 这里插入不合适

        while (stack.size() > 0 || nullptr != root) {
            //遍历左子树
            while (root) {
                stack.push_back(root);
                root = root->left; //move
            }
            // 走到这里说明 root ==nill

            //访问节点
            root = stack.back();
            stack.pop_back();
            //判断是否逆序
            if (nullptr != pre && pre->val > root->val) {
                if (nullptr == first) {
                    first = pre;
                }
                second = root;
            }
            pre = root; //下次访问

            //遍历右子树
            root = root->right;
        }
        //03 swap
        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};
// @lc code=end
