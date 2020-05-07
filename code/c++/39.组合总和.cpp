/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (67.26%)
 * Likes:    430
 * Dislikes: 0
 * Total Accepted:    43.7K
 * Total Submissions: 65K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的数字可以无限制重复被选取。
 *
 * 说明：
 *
 *
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 *
 *
 * 示例 1:
 *
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * 示例 2:
 *
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 */

// @lc code=start
<<<<<<< HEAD
//第四个版本  背包问题 执行用时 :28 ms -12ms 这个效率并不高呀。
//时间复杂度： O(2^n)  
//空间复杂度：O (1) 
=======
/*参考代码：https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/
 https://leetcode-cn.com/problems/combination-sum/solution/hui-shuo-suan-fa-di-gui-java-by-longchenghuang/
 
 测试
 1. 加入输入一个元素a[1], k=100,输出 {100个1}，递归层次不是1  元素可重复选取。
 2.  candidates = [2,3,6,7], target = 7, 每次n=4全部计算一次。 集合特点是顺的。

*/
>>>>>>> f7bb51052ebcbb0a8d4688de6d9073cffca93d39
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {

    vector<vector<int>> output;
    int len = candidates.size();
    if (0 == len) {
      return output;
    }
    vector<int> path;
    int sum = 0;
    int start = 0;

    dfs(candidates, target, sum, start, path, output);
    return output;
  }

  void dfs(vector<int> &candidates, int &target, int sum, int start,
           vector<int> &path, vector<vector<int>> &output) {

    if (sum == target) {
      output.push_back(path);
      return; //遗忘返回值，寻找目标就结束，递归推出条件你忘记啦 
              //你还是对个背包算法本质不清楚
    }
    if (start >= candidates.size() || sum > target) {
      return; // 你sb了 && 是同时成立的， 你还是对个背包算法本质不清楚
    }
    //采用
    if (sum + candidates[start] <= target) {
      //添加if 判断减少函数调用，提高16ms 提示效果很明显
      path.push_back(candidates[start]);
      dfs(candidates, target, sum + candidates[start], start, path, output);
      // path.back();// Returns a reference to the last element in the vector.
      // Removes the last element in the vector, effectively reducing the
      path.pop_back(); //对stl里面功能还是没有想清楚怎么用。模糊了害死人。
    }

    //不采用
    dfs(candidates, target, sum, start + 1, path, output);
  }
};
/** 第三版本 排序后，在剪纸，如果发现不满足的，后续的不满足
 执行用时 :8 ms, 在所有 cpp 提交中击败了99.76% 的用户
内存消耗 :9.2 MB, 在所有 cpp 提交中击败了96.35%的用户
 **/
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {

    vector<vector<int>> output;
    int len = candidates.size();
    if (0 == len) {
      return output;
    }

    sort(candidates.begin(), candidates.end(), less<int>());
    vector<int> path;
    int sum = 0;
    int start = 0;
    dfs(candidates, target, sum, start, path, output);
    return output;
  }

  void dfs(vector<int> &candidates, int &target, int sum, int start,
           vector<int> &path, vector<vector<int>> &output) {
    if (sum > target) {
      return;
    }
    if (sum == target) {
      output.push_back(path);
    }
    for (int i = start; i < candidates.size(); i++) {
      if (sum + candidates[i] > target) {
        break; //因为不知道具体元素大小，需要每次都判断
      }
      path.push_back(candidates[i]);
      //因为每个数字都可以使用无数次，所以递归还可以从当前元素开始
      //之前的元素也可使用，但是造成重复集合，不是全排序问题
      dfs(candidates, target, sum + candidates[i], i, path, output);
      path.pop_back();
    }
  }
};
//第二版本
//规定不能从小于自己索引位置剩余元素选取
//每次选择都n-i个可能,求的集合，不是全排序
//执行用时 :16 ms  
//时间复杂度： O(2^n)  
//空间复杂度：O (1)  
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {

    vector<vector<int>> output;
    int len = candidates.size();
    if (0 == len) {
      return output;
    }
    // sort这个可以去掉，索引控制不会重复<i,j> <j,i> 不是具体内容
    sort(candidates.begin(), candidates.end(), less<int>());
    vector<int> path;
    int sum = 0;
    int start = 0;
    dfs(candidates, target, sum, start, path, output);
    return output;
  }

  void dfs(vector<int> &candidates, int &target, int sum, int start,
           vector<int> &path, vector<vector<int>> &output) {
    if (sum > target) {
      return;
    }
    if (sum == target) {
      output.push_back(path);
    }
    for (int i = start; i < candidates.size(); i++) {
      if (sum + candidates[i] > target) {
        // continue;
        break;
      }
      path.push_back(candidates[i]);
      //因为每个数字都可以使用无数次，所以递归还可以从当前元素开始
      //之前的元素也可使用，但是造成重复集合，不是全排序问题
      dfs(candidates, target, sum + candidates[i], i, path, output);
      path.pop_back();
    }
  }
};

//第一版本 每次选择都n个可能，会持续重复元素 结果错误的
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {

    vector<vector<int>> output;
    int len = candidates.size();
    if (0 == len) {
      return output;
    }
    vector<int> path;
    dfs(candidates, target, 0, path, output);
    return output;
  }

  void dfs(vector<int> &candidates, int &target, int sum, vector<int> &path,
           vector<vector<int>> &output) {
    if (sum > target) {
      return
    }
    if (sum == target) {
      output.push_back(path);
    }
    for (int i = 0; i < candidates.size(); i++) {
      if (sum + candidates[i] > target) {
        continue;
      }
      path.push_back(candidates[i]);
      dfs(candidates, target, sum + candidates[i], path, output);
      path.pop_back(candidates[i]);
    }
  }
};
// @lc code=end
