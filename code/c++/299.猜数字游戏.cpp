/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 *
 * https://leetcode-cn.com/problems/bulls-and-cows/description/
 *
 * algorithms
 * Easy (48.17%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    14.6K
 * Total Submissions: 30.2K
 * Testcase Example:  '"1807"\n"7810"'
 *
 * 你在和朋友一起玩 猜数字（Bulls and Cows）游戏，该游戏规则如下：
 * 
 * 
 * 你写出一个秘密数字，并请朋友猜这个数字是多少。
 * 朋友每猜测一次，你就会给他一个提示，告诉他的猜测数字中有多少位属于数字和确切位置都猜对了（称为“Bulls”,
 * 公牛），有多少位属于数字猜对了但是位置不对（称为“Cows”, 奶牛）。
 * 朋友根据提示继续猜，直到猜出秘密数字。
 * 
 * 
 * 请写出一个根据秘密数字和朋友的猜测数返回提示的函数，返回字符串的格式为 xAyB ，x 和 y 都是数字，A 表示公牛，用 B 表示奶牛。
 * 
 * 
 * xA 表示有 x 位数字出现在秘密数字中，且位置都与秘密数字一致。
 * yB 表示有 y 位数字出现在秘密数字中，但位置与秘密数字不一致。
 * 
 * 
 * 请注意秘密数字和朋友的猜测数都可能含有重复数字，每位数字只能统计一次。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: secret = "1807", guess = "7810"
 * 输出: "1A3B"
 * 解释: 1 公牛和 3 奶牛。公牛是 8，奶牛是 0, 1 和 7。
 * 
 * 示例 2:
 * 
 * 输入: secret = "1123", guess = "0111"
 * 输出: "1A1B"
 * 解释: 朋友猜测数中的第一个 1 是公牛，第二个或第三个 1 可被视为奶牛。
 * 
 * 
 * 
 * 说明: 你可以假设秘密数字和朋友的猜测数都只包含数字，并且它们的长度永远相等。
 * 
 */

// @lc code=start

class Solution
{
public:
    //判断一个字符是否在一个字符串中存在，一定要必须等字符串全部遍历吗？
    //当然，不然怎么知道，存在不存在呢？这样奇异技巧 可以不去了解。
    string getHint(string secret, string guess)
    {
        int bulls = 0; //数字出现在秘密数字中，且位置都与秘密数字一致
        int cows = 0;  //在秘密数字中，但位置与秘密数字不一致

        unordered_map<char, int> data; //统计字符串出现次数，
        // 如果大于标识出现过，secret出现了，guess查询到了
        // 如果小于0，guess出现了，secret还当发现
        // 等于0 2边都没有出现
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            if (data[guess[i]]-- > 0)
            {
                cows++;
            }

            if (data[secret[i]]++ < 0)
            {
                cows++;
            }
        }

        return to_string(bullsCount) + "A" + to_string(cowsCount) + "B";
    }
};

class Solution1
{
public:
    //难点：跟位置顺序有关系 数据结果哪些？unordered_map 跟输入顺序有关系吗？
    //同一个字符 在2边出现次数一样。
    string getHint(string secret, string guess)
    {
        //位置都与秘密数字一致。
        int bullsCount = 0;

        //数字出现在秘密数字中，但位置与秘密数字不一致 //unordered_map
        int cowsCount = 0;
        unordered_map<char, int> data;

        //并且它们的长度永远相等。
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bullsCount++;
            }
            data[secret[i]]++;
        }
        //弥补了跟位置没有关系的缺点。
        for (int i = 0; i < guess.size(); i++)
        {
            //出现过，含有重复数字，每位数字只能统计一次。
            if (data[guess[i]] > 0)
            {
                cowsCount++;
                data[guess[i]]--;
            }
        }

        if (bullsCount > 0)
        {
            cowsCount -= bullsCount; //删除位置一致的。
        }
        return to_string(bullsCount) + "A" + to_string(cowsCount) + "B";
    }
};
// @lc code=end
