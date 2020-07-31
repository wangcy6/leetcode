/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 *
 * https://leetcode-cn.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (48.88%)
 * Likes:    125
 * Dislikes: 0
 * Total Accepted:    28.5K
 * Total Submissions: 58K
 * Testcase Example:  '16'
 *
 * 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 16
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: 5
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
    bool isPowerOfFour(int num)
    {
        if (num == 0)
        {
            return false;
        }

        while (num % 4 == 0)
        {
            num /= 4;
        }

        return num == 1;
    }
};
// @lc code=end
