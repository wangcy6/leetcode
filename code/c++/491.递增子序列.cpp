/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 *
 * https://leetcode-cn.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (48.93%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    12.6K
 * Total Submissions: 24.2K
 * Testcase Example:  '[4,6,7,7]'
 *
 * 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
 * 
 * 示例:
 * 
 *  
 * 输入: [4, 6, 7, 7]
 * 输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 * 
 * 说明:
 * 
 * 
 * 给定数组的长度不会超过15。
 * 数组中的整数范围是 [-100,100]。
 * 给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
 *  */

/*
1 .7 7不是递增元素呀。意思是说不小于
2.错误测试    
  [4, 6, 7, 7]

  [4, 6, 7 ][4, 6, 7] 删除重复一个元素

 [4, 6, 7, 7] 在上面基础上，添加7，不能排序直接删除7

 3. 测试：[1,1,1,2,2,2,3,3,3]



*/

// @lc code=start
class Solution {
public:
    /***
     * 01 输入条件元素有重复吗？ 有，
     * 02 递增子序列 就是从root节点到叶子节点组成任意大于2的路径。
     * 03 抽象：数组长度是n，就是n叉tree，tree的高度是n 给定数组的长度不会超过15
     * 04 利用栈递归回溯遍历。
     * 05 子序列不重复 4  6  7  7 ，如果4 root节点遍历，如果后续重复的可以节省
     * 06 关键 如何从 2层循环思路想到递归回溯。我是看别人答案知道的。
     * 数组 --->tree 递增子序列 a>b>c>d 这个路径，然后联想大tree
     ***/
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> stack;
        dfs(0, stack, nums, result);
        return result;
    }

    void dfs(int start, vector<int>& stack, vector<int>& nums, vector<vector<int>>& result)
    {

        //每个合法节点都是 递增子序列(这里不是叶子节点才是)
        if (stack.size() >= 2) {
            result.push_back(stack);
        }

        if (start >= nums.size()) {
            return; //越界
        }

        unordered_set<int> used; //  注意是每次递归，如果发现重复元素不递归。不是全局重复，这是不一样地方

        for (int i = start; i < nums.size(); i++) {

            int cur = nums[i];
            //必须是递增序列
            if (stack.size() > 0 && cur < stack.back()) {

                continue;
            }
            if (used.count(cur) == 1) { //[4, 6, 7][4, 6, 7] 删除重复一个元素
                // return;
                continue; //是继续递归，而不是退出循环。
            }
            stack.push_back(cur);

            dfs(i + 1, stack, nums, result);

            stack.pop_back();

            used.insert(cur); //在回溯的时候，记录这个元素用过了，后面不能再用了
        }
    }
};

// @lc code=end
