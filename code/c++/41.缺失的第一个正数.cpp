/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (36.88%)
 * Likes:    307
 * Dislikes: 0
 * Total Accepted:    27.8K
 * Total Submissions: 75.3K
 * Testcase Example:  '[1,2,0]'
 *
 * 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
 *
 * 示例 1:
 *
 * 输入: [1,2,0]
 * 输出: 3
 *
 *
 * 示例 2:
 *
 * 输入: [3,4,-1,1]
 * 输出: 2
 *
 *
 * 示例 3:
 *
 * 输入: [7,8,9,11,12]
 * 输出: 1
 *
 *
 * 说明:
 *
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
 *
 */
/** 测试用例
 */
/** 分析
 *
 * 桌上有十个苹果，要把这十个苹果放到九个抽屉里，无论怎样放，
 *
我们会发现至少会有一个抽屉里面放不少于两个苹果。这一现象就是我们所说的“抽屉原理”。 
 * 抽屉原理的一般含义为：“如果每个抽屉代表一个集合，
 * 每一个苹果就可以代表一个元素，假如有n+1个元素放到n个集合中去，
 * 其中必定有一个集合里至少有两个元素。” 抽屉原理有时也被称为鸽巢原理。
 * 它是组合数学中一个重要的原理 [1]  。
 * https://www.cnblogs.com/kkun/archive/2011/11/23/bucket_sort.html
 * https://www.cnblogs.com/linyujun/p/5210466.html
 *
 * [LeetCode] 287. Find the Duplicate Number 寻找重复数
 * https://www.cnblogs.com/grandyang/p/4843654.html
 * https://www.youtube.com/watch?v=i4kBcvA3OV4
 *https://leetcode-cn.com/problems/find-the-duplicate-number/solution/kuai-man-zhi-zhen-de-jie-shi-cong-damien_undoxie-d/
https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-huan-ru-kou-by-powcai/
 *https://leetcode-cn.com/problems/linked-list-cycle-ii/
https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-kuai-man-zhi-zhen-zhu-xing-jie-shi-pytho/
 * /
 *
/**
 * 类似问题：
 * https://leetcode-cn.com/problems/couples-holding-hands/
 * https://leetcode-cn.com/problems/missing-number/
 * **/
// @lc code=start
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {}
};
// @lc code=end
