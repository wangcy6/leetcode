/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 *
 * https://leetcode-cn.com/problems/water-and-jug-problem/description/
 *
 * algorithms
 * Medium (35.11%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    24.7K
 * Total Submissions: 70.4K
 * Testcase Example:  '3\n5\n4'
 *
 * 有两个容量分别为 x升 和 y升 的水壶以及无限多的水。
 * 请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
 * 如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。
 * 
 * 你允许：
 * 装满任意一个水壶
 * 清空任意一个水壶
 * 从一个水壶向另外一个水壶倒水，直到装满或者倒空
 *  
 * 示例 1: (From the famous "Die Hard" example)
 * 
 * 输入: x = 3, y = 5, z = 4
 * 输出: True
 * 
 * 示例 2:
 * 输入: x = 2, y = 6, z = 5
 * 输出: False
 * 
 *  题目 不理解里面含义
 */

// @lc code=start

class Solution
{
public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (z < 0 || z > x + y)
            return false;

        std::set<int> s;
        std::queue<int> q({0});

        while (q.size() > 0)
        {
            int n = q.front();
            if (n + x <= x + y && true == s.insert(n + x).second)
                q.push(n + x);
            if (n + y <= x + y && true == s.insert(n + y).second)
                q.push(n + y);
            if (n - x >= 0 && true == s.insert(n - x).second)
                q.push(n - x);
            if (n - y >= 0 && true == s.insert(n - y).second)
                q.push(n - y);
            if (s.end() != s.find(z))
                return true;

            q.pop();
        }

        return false;
    }
};

class Solution1
{
    inline pair<int, int> op(int type, const pair<int, int> &state, int x, int y)
    {
        switch (type)
        {
        case 0:
            return make_pair(x, state.second);
        case 1:
            return make_pair(state.first, y);
        case 2:
            return make_pair(0, state.second);
        case 3:
            return make_pair(state.first, 0);
        case 4:
        {
            int move = min(state.first, y - state.second);
            return make_pair(state.first - move, state.second + move);
        }
        case 5:
        {
            int move = min(x - state.first, state.second);
            return make_pair(state.first + move, state.second - move);
        }
        }
        return make_pair(0, 0);
    }
    struct HashPair
    {
        size_t operator()(const pair<int, int> &key) const noexcept
        {
            return (size_t(key.first) << 31) | size_t(key.second);
        }
    };
    inline int64_t Hash(int x, int y)
    {
        return int64_t(x) << 32 | y;
    }

public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y < z)
        { //加了一个很蠢的剪枝，作用比较大。
            return false;
        }
        unordered_set<int64_t> mark; //pair<int, int> 换成int64_t, 但是意义不大。
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        while (q.empty() == false)
        {
            auto f = q.front();
            q.pop();
            if (f.first + f.second == z)
            {
                return true;
            }
            for (int i = 0; i < 6; i++)
            {
                auto next = op(i, f, x, y);
                int64_t h = Hash(next.first, next.second);
                if (mark.find(h) != mark.end())
                {
                    continue;
                }
                mark.insert(h);
                q.push(next);
            }
        }
        return false;
    }
};

// @lc code=end
