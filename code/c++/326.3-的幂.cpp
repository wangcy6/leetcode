/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 *
 * https://leetcode-cn.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (46.89%)
 * Likes:    119
 * Dislikes: 0
 * Total Accepted:    52.3K
 * Total Submissions: 111.4K
 * Testcase Example:  '27'
 *
 * 给定一个整数，写一个函数来判断它是否是 3 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 27
 * 输出: true 3*3*3
 * 
 * 
 * 示例 2:
 * 
 * 输入: 0
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: 9
 * 输出: true 3*3
 * 
 * 示例 4:
 * 
 * 输入: 45
 * 输出: false
 * 
 * 进阶：
 * 你能不使用循环或者递归来完成本题吗？
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (0 == n)
        {
            return false;
        }
        while (0 == n % 3)
        {
            n /= 3;
        }
        return n == 1;
    }
};
// @lc code=end
