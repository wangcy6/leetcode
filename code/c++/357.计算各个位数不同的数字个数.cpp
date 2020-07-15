/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 *
 * https://leetcode-cn.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (51.09%)
 * Likes:    74
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 21K
 * Testcase Example:  '2'
 *
 * 给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10^n 。
 * 
 * 示例:
 * 
 * 输入: 2
 * 输出: 91 
 * 解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。
 * 
 * https://zxi.mytechroad.com/blog/math/leetcode-357-count-numbers-with-unique-digits/
 * https://www.youtube.com/watch?v=OkJKxoDbQ_c
 */

// @lc code=start
class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
    }
};
// @lc code=end

class Solution
{
public
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        return dfs(Math.min(10, n), 0, new boolean[10]);
    }

private
    int dfs(int n, int idx, boolean[] used)
    {
        int count = 0;
        if (idx != n)
        {
            for (int i = 0; i < 10; i++)
            {
                // 剪枝：多位数时，第一个数字不能为0
                if (i == 0 && n > 1 && idx == 1)
                {
                    continue;
                }
                // 剪枝：不能使用用过的数字
                if (used[i])
                {
                    continue;
                }
                used[i] = true;
                count += dfs(n, idx + 1, used) + 1;
                used[i] = false;
            }
        }
        return count;
    }
}

// class Solution {
//     /**
//      * 排列组合：n位有效数字 = 每一位都从 0~9 中选择，且不能以 0 开头
//      * 1位数字：0~9                      10
//      * 2位数字：C10-2，且第一位不能是0      9 * 9
//      * 3位数字：C10-3，且第一位不能是0      9 * 9 * 8
//      * 4位数字：C10-4，且第一位不能是0      9 * 9 * 8 * 7
//      * ... ...
//      * 最后，总数 = 所有 小于 n 的位数个数相加
//      */
//     public int countNumbersWithUniqueDigits(int n) {
//         if (n == 0) return 1;
//         int first = 10, second = 9 * 9;
//         int size = Math.min(n, 10);
//         for (int i = 2; i <= size; i++) {
//             first += second;
//             second *= 10 - i;
//         }
//         return first;
//     }
// }

// 作者：rainlight
// 链接：https://leetcode-cn.com/problems/count-numbers-with-unique-digits/solution/javaduo-jie-fa-hui-su-dong-tai-gui-hua-mei-ju-by-r/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。