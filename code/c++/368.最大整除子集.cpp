/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 *
 * https://leetcode-cn.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (38.17%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 20.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给出一个由无重复的正整数组成的集合，找出其中最大的整除子集，子集中任意一对 (Si，Sj) 都要满足：Si % Sj = 0 或 Sj % Si =
 * 0。
 * 
 * 如果有多个目标子集，返回其中任何一个均可。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2] (当然, [1,3] 也正确)
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,4,8]
 * 输出: [1,2,4,8]
 * 
 * 01 题目没怎么看明白 ，最大的整除子集
 * 02 我能做遍历一次，判断是否重复 需要2个空间，
 * 03 2层循环，第一次 判断每个字符 是否被整数，然后放集合去重，插入输出结果
 *    第二：就是每个比较一次。
 * 
 * 阅读1次 https://leetcode-cn.com/problems/largest-divisible-subset/solution/zui-da-zheng-chu-zi-ji-by-leetcode/
 */
}
;
// @lc code=start
class Solution
{
public:
    // vector<int> largestDivisibleSubset(vector<int> &nums)
    // {
    //     for (遍历一次)
    //     {
    //         for (和剩余元素笔记)
    //         {
    //             if (整除)
    //             {
    //                 //集合处重复
    //                 //添加
    //             }
    //         }
    //     }
    // }
};
// @lc code=end
