/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (56.07%)
 * Likes:    254
 * Dislikes: 0
 * Total Accepted:    32.2K
 * Total Submissions: 57.1K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 * 
 * 示例 1:
 * 
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 说明: 你可以假设 n 不小于 2 且不大于 58。
 * 
 * //https://leetcode-cn.com/problems/integer-break/solution/shi-yong-jing-dian-er-wei-dpbei-bao-wen-ti-tian-bi/
 * https://leetcode-cn.com/problems/integer-break/solution/ba-yi-ba-zhe-chong-ti-de-wai-tao-343-zheng-shu-cha/
 * 
 * https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
 * - 最大乘积
 * n=2:  1+1  -->1*1=1;   		    dp[2]=1;
n=3:  2+1  -->2*1=2;   				dp[3]=2;
n=4:  2+2  -->2*2=4;   				dp[4]=4;
n=5:  3+2  -->3*2=6;   				dp[5]=6;
貌似看不出规律，别急再多写几个
n=6:  3+3  -->3*3=9;                 dp[6]=9;
n=7:  4+3  -->4*3=12;-->dp[4]*3=12   dp[7]=12;
n=8:  5+3  -->6*3=12;-->dp[5]*3=18   dp[8]=18;
n=9:  6+3  -->9*3=12;-->dp[6]*3=27   dp[9]=27;
n=10: 7+3  -->12*3=36;-->dp[7]*3=12   dp[10]=36
if(n>=7)
	dp[n] = dp[n-3]*3;
作者：xiao-bai-323
链接：https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/kan-bu-dong-suan-wo-shu-de-ti-jie-dong-tai-gui-hua/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

// @lc code=start
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                int t = max(max(dp[j] * dp[i - j], max(dp[j] * (i - j), j * dp[i - j])), j * (i - j));
                dp[i] = max(dp[i], t);
            }
        }
        return dp[n];
    }
};
// @lc code=end
