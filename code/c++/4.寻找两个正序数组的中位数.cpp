/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (38.29%)
 * Likes:    2794
 * Dislikes: 0
 * Total Accepted:    212.6K
 * Total Submissions: 555K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
 * 
 * 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 */

// @lc code=start
class Solution
{
public:
    //寻找两个正序数组的中位数
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        //根据中位数的定义，当 m+n 是奇数时，经过观察发现 中位数是两个有序数组中的第 (m+n)/2+1个元素，需要+1
        //bug3 需要+1操作
        if ((m + n) % 2 != 0)
        {
            int top = (m + n) / 2 + 1;
            //问题转成top k
            int mid = topk(nums1, nums2, top);
            //cout << "奇数:" << top << " = " << mid << endl;
            return mid;
        }
        else
        { //当 m+n是偶数时，中位数 经过观察发现  是两个有序数组中的第 (m+n)/ 个元素和第 (m+n)/2+1 个元素的平均值
            int k1 = (m + n) / 2;
            int k2 = k1 + 1;
            //问题转成top k
            int k11 = topk(nums1, nums2, k1);
            int k22 = topk(nums1, nums2, k2);
            //cout << "偶数:" << k11 << " = " << k22 << " = " << (k11 + k22) / 2.0 << endl;
            return (k11 + k22) / 2.0;
        }
    }
    //利用堆 顺序选择k个最小元素
    int topk(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n1 = 0;
        int n2 = 0;
        int topk = 0;
        //bug2  循环k次，不能等于0
        while (k > 0)
        {
            k--;
            //范围都存在
            if (n1 < nums1.size() && n2 < nums2.size())
            {
                if (nums1[n1] < nums2[n2])
                {

                    topk = nums1[n1];
                    n1++;
                }
                else
                {
                    topk = nums2[n2];
                    n2++;
                }
            }
            else
            {
                /* bug1 这里是上面的else条件*/

                //只有第一个符合条件
                if (n1 < nums1.size() && n2 >= nums2.size())
                {
                    topk = nums1[n1];
                    n1++;
                }

                if (n2 < nums2.size() && n1 >= nums1.size())
                {
                    topk = nums2[n2];
                    n2++;
                }
            }
        }

        return topk;
    }
};
// @lc code=end
