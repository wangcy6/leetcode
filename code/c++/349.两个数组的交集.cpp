/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (69.49%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    82.9K
 * Total Submissions: 118.2K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 上来一看就梦了，心慌 然后感觉不太好
 * 但是我还是标准算法分析去思考这个题目，get it
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> res;
        map<int, int> hash;

        //for循环遍历
        for (int i = 0; i < nums1.size(); i++)
        {

            for (int j = 0; j < nums2.size(); j++)
            {
                //判断是否相等
                if (nums1[i] == nums2[j])
                {
                    if (hash.count(nums1[i]) == 1)
                    {
                        //有重复
                    }
                    else
                    {

                        res.push_back(nums1[i]);
                        hash[nums1[i]] = nums1[i];
                    }

                    break;
                }
            }
        }

        return res;
    }
};
// @lc code=end
