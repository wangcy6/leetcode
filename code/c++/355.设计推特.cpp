/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 *
 * https://leetcode-cn.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (41.45%)
 * Likes:    145
 * Dislikes: 0
 * Total Accepted:    16.5K
 * Total Submissions: 40K
 * Testcase Example:  '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n' +
  '[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * 
 * 设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：
 * 
 * 
 * postTweet(userId, tweetId): 创建一条新的推文
 * getNewsFeed(userId):
 * 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
 * follow(followerId, followeeId): 关注一个用户
 * unfollow(followerId, followeeId): 取消关注一个用户
 * 
 * 
 * 示例:
 * 
 * 
 * Twitter twitter = new Twitter();
 * 
 * // 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
 * twitter.postTweet(1, 5);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
 * twitter.getNewsFeed(1);
 * 
 * // 用户1关注了用户2.
 * twitter.follow(1, 2);
 * 
 * // 用户2发送了一个新推文 (推文id = 6).
 * twitter.postTweet(2, 6);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
 * // 推文id6应当在推文id5之前，因为它是在5之后发送的.
 * twitter.getNewsFeed(1);
 * 
 * // 用户1取消关注了用户2.
 * twitter.unfollow(1, 2);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
 * // 因为用户1已经不再关注用户2.
 * twitter.getNewsFeed(1);
 * 
 * 
 */

// @lc code=start
class Twitter
{
private:
    /*2个哈希表*/
    unordered_map<int, set<int>> userId2follow;
    unordered_map<int, stack<pair<int, int>>> userId2Tweet;
    int counter; //计数器
public:
    Twitter()
    {
        counter = 0; //计数器初始化
    }

    void postTweet(int userId, int tweetId)
    {
        /*添加推特，记得counter++*/
        userId2Tweet[userId].push({tweetId, counter++});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        /*加入userId本身的推特栈*/
        vector<stack<pair<int, int>>> tmp = {userId2Tweet[userId]};

        for (set<int>::iterator ite = userId2follow[userId].begin(); ite != userId2follow[userId].end(); ite++)
        {
            /*注意用户关注其本身的操作！这里要将这种情况排除*/
            if (*ite != userId)
                /*将userId所关注的其他用户的推特栈加入tmp*/
                tmp.push_back(userId2Tweet[*ite]);
        }

        for (int i = 0; i < 10; i++)
        {
            /*记录最大值和索引*/
            int maxindex, maxval = -1;
            for (int j = 0; j < tmp.size(); j++)
            {
                if (!tmp[j].empty() && tmp[j].top().second > maxval)
                {
                    maxval = tmp[j].top().second; //保存最大值
                    maxindex = j;                 //保存索引
                }
            }

            if (maxval == -1)
                break;                                //所有栈都为空
            res.push_back(tmp[maxindex].top().first); //将推特id加入res
            tmp[maxindex].pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId)
    {
        userId2follow[followerId].insert(followeeId); //关注
    }

    void unfollow(int followerId, int followeeId)
    {
        userId2follow[followerId].erase(followeeId); //取关
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
