/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (39.89%)
 * Likes:    673
 * Dislikes: 0
 * Total Accepted:    97.6K
 * Total Submissions: 243.4K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。
 * 编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
 * 如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3 
 * 解释: 11 = 5 + 5 + 1
 * 
 * 示例 2:
 * 
 * 输入: coins = [2], amount = 3
 * 输出: -1
 * 
 * 
 * 
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
 *  阅读：https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/
 *   耗时：
 *   
 *  阅读：https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/
 *  耗时：
 *  输出：
 * 
 *  阅读： https://leetcode-cn.com/problems/coin-change/solution/javadi-gui-ji-yi-hua-sou-suo-dong-tai-gui-hua-by-s/
 *  
 */

// @lc code=start

class Solution
{
public:
    //输入: coins = [1, 2, 5], amount = 1000
    //解释: 11 = 5 + 5 + 1
    // (12 ms)  95.2 % of cpp submissions
    int coinChange(vector<int> &coins, int amount)
    {
        int res = INT_MAX;
        sort(coins.begin(), coins.end(), greater<int>());
        //虽然是全部遍历，第一元素必须最大元素，加快进行剪枝
        //eg1  [244,125,459,120,316,68,357,320] 9793 n太不适合动态规划,无法从最小元素开始
        //eg2  [186,419,83,408] 6249, n太不适合动态规划,无法从最小元素开始
        dfs(coins, amount, 0, 0, res);

        return res == INT_MAX ? -1 : res;
    }
    //递归回溯
    void dfs(vector<int> &coins, int amount, int index, int total, int &res)
    {
        if (amount < 0)
        {
            return; //组合不不成立
        }
        if (amount == 0)
        {
            res = min(res, total); //依然全部遍历
            return;
        }
        if (index >= coins.size())
        {
            return; //组合不不成立。 coins = [2], amount = 3
        }
        //每种硬币的数量是无限的
        //合并重复的dfs.
        //11 = 5 + 5 + 1
        //11 = 1 + 1+ 1+1.....
        //dfs（）

        int nums = amount / coins[index];
        //nums 从大到小常识，res 默认是最大值。不然已经计算过一次了。
        for (int j = nums; j >= 0 && (total + j) < res; j--)
        {
            // //最重要 //[470,35,120,81,121] 9825
            // if ((total + j) > res)
            // {
            //     continue; //剪枝，
            // } 这样不行  优化for循环，判断放到外面去
            //[ 288, 160, 10, 249, 40, 77, 314, 429 ] 9208
            //index 不是排序问题，是组合问题。[2,1] [1,2] 属于同一个问题。
            //j =0 代表不适用该硬币。
            dfs(coins, amount - j * coins[index], index + 1, total + j, res);
        }
    }
};

class Solution6
{
public:
    //输入: coins = [1, 2, 5], amount = 1000
    //解释: 11 = 5 + 5 + 1
    //[186,419,83,408] 6249
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end(), greater<int>()); // 5 2 1
        return dfs(coins, amount, 0, 0);
    }

    int dfs(vector<int> &coins, int amount, int sum, int index)
    {
        if (amount < 0)
        {
            return -1; //组合不不成立
        }
        if (amount == 0)
        {
            return sum;
        }
        if (index >= coins.size())
        {
            return -1;
        }
        //你可以认为每种硬币的数量是无限的。

        int nums = amount / coins[index];
        for (int j = nums; j >= 0; j--)
        {
            int temp = dfs(coins, amount - j * coins[index], sum + j, index + 1);
            if (temp > 0)
            {
                return temp;
            }
        }

        return -1;
    }
};

class Solution4
{
public:
    //164 ms  beats 24.38 % of cpp submissions ,为什么动态规划效果不佳
    ////[1,2,5],100 target 越大，循环次数越多
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 0); //dp[n] 表示钱币n可以被换取的最少的硬币数，不能换取就为-1. 第一个默认为0
        dp[0] = 0;
        //coins = [1, 2, 5], amount = 11
        //dp[1]={dp[1-1],dp[1-2],dp[1-5]}+1;
        for (int target = 1; target <= amount; target++)
        {
            int total = INT_MAX;
            for (int i = 0; i < coins.size(); i++)
            {

                if (coins[i] > target || dp[target - coins[i]] == -1)
                {
                    continue; //组合不成立
                }
                total = min(total, dp[target - coins[i]] + 1); // target从小到大计算，target之前一定计算过 .节点个数计算
            }
            dp[target] = (total == INT_MAX ? -1 : total);
        }

        return dp[amount];
    }
};
class Solution2
{
public:
    //144 ms  43.1 % of cpp submissions
    //空间复杂度：O(S) ,时间复杂度：O(Sn)，其中 S是金额，n是面额数
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 0); //dp[n] 表示钱币n可以被换取的最少的硬币数，不能换取就为-1.
        //节点个数通过参数从下到上返回,不需要对其初始第一个数值。这里是递归
        return dfs(coins, amount, dp);
    }
    int dfs(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount < 0)
        {
            return -1; //组合不成立,
        }

        if (amount == 0)
        {
            return 0; //类比求tree的高度
        }

        if (dp[amount] != 0)
        {
            return dp[amount]; // 0表示没有计算，-1 和大于0 表示计算完毕。
        }
        int total = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (coins[i] > amount)
            {
                continue; //无法找零
            }
            //最少的硬币数
            int temp = dfs(coins, amount - coins[i], dp); //变化
            if (temp < 0)
            {
                continue;
                //零钱不够 eg : [2] 3,返回负数的不能参与计算。
            }
            total = min(total, temp + 1);
            // 变化
        }
        dp[amount] = (total == INT_MAX ? -1 : total);

        return dp[amount];
    }
};

class Solution1
{
public:
    //[1,2,5],100
    int coinChange(vector<int> &coins, int amount)
    {
        int res = INT_MAX;
        dfs(coins, amount, 0, res);
        // 如果没有任何一种硬币组合能组成总金额，返回 -1
        return res == INT_MAX ? -1 : res;
    }
    void dfs(vector<int> &coins, int amount, int count, int &res)
    {
        if (amount < 0)
        {
            return; //组合不成立
        }

        if (amount == 0)
        {
            res = min(res, count); //叶子节点
        }
        //你可以认为每种硬币的数量是无限的。
        for (int i = 0; i < coins.size(); i++)
        {
            //从上到下。节点个数通过参数传递。
            dfs(coins, amount - coins[i], count + 1, res);
        }
    }
};
// @lc code=end
