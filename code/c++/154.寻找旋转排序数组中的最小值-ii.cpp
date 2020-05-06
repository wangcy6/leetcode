/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
  int findMin(vector<int> &nums) {
    int begin = 0;
    int end = nums.size() - 1;
    int mid = begin;
    if (nums[end] > nums[begin]) {
      return nums[begin];
    }
    while (begin < end) {

      mid = (begin + end) / 2;

      if (nums[mid] > nums[end]) {
        begin = mid + 1;
      } else if (nums[mid] < nums[end]) {
        end = mid;
      } else {  
        end--;
      }
    }
    return nums[begin];
  }

  int findMin2(vector<int> &nums) {
    int begin = 0;
    int end = nums.size() - 1;
    int mid = begin; //返回结果
    if (begin == end) {
      return nums[mid];
    }

    while (nums[begin] >= nums[end]) {
      if (end - begin == 1) {
        begin = end;
        break;
      }
      mid = (begin + end) / 2;

      if (nums[mid] > nums[end]) {
        begin = mid + 1;
      } else if (nums[mid] < nums[end]) {
        end = mid;
      } else {
        end--;
      }
    }
    return nums[begin];
  }
};
// @lc code=end
