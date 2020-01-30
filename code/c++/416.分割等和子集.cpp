/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (43.57%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 26.8K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 * 注意:
 *
 *
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 *
 *
 * 示例 1:
 *
 * 输入: [1, 5, 11, 5]
 *
 * 输出: true
 *
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 *
 *
 *
 *
 * 示例 2:
 *
 * 输入: [1, 2, 3, 5]
 *
 * 输出: false
 *
 * 解释: 数组不能分割成两个元素和相等的子集.
 *
 *https://leetcode.com/problems/partition-equal-subset-sum/discuss/90588/Concise-C%2B%2B-Solution-summary-with-DFS-DP-BIT
 *
 *https://leetcode.com/problems/partition-equal-subset-sum/discuss/453387/C%2B%2B-or-DP-or-Easy-to-understand
 *
 * 
 *  [1,2,5] false 
 *  [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100]
 */

// @lc code=start
/*https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/java-hui-su-fa-jie-fa-2ms-by-wang_dong/
*/
class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    if (nums.empty())
      return true;
    int target = accumulate(nums.begin(), nums.end(), 0);
    if (target % 2 != 0)
      return false;
    target /= 2;

    return canPartition(nums,target,0);


  }

  bool canPartition(vector<int> &nums,int target,int index)
  {

    if (index ==nums.size())
    {
       return false;//越界
    }


    if (target ==0) {
       return true;
    }else if( target < 0)
    {
      return false;
    }

    //go 
   if (true ==canPartition(nums,target-nums[index],index+1))
   {
      return true;
   }
    
   int repeated =index+1;
   while (repeated<nums.size()-1 && nums[repeated] == nums[index]){

   repeated++;
   
   }
   
   return canPartition(nums,target,repeated);
   
  }
};

//https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/c-01bei-bao-zhun-que-zhi-by-ekulelu/


// /**
//  *
//  * 子集和问题，对标准的回溯法的优化
//  * 举个例子，设有数组a[6] = { 1, 2, 3, 4, 5, 6 }，sum = 10，
//  * 则满足和为10的所有组合
//  聪明的你一眼看出来
 
//  {1, 2, 3, 4}.
// {1, 3, 6},
// {1, 4, 5} ,
// {2, 3, 5},
// {4, 6},
// 如果过去不知道，那么现在知道了

// 你发现：
// 1 虽然都有可能，存在路径 分别是 1和 2 ，4，开始的node 满足条件，  3 4 5 6 开头的节点不满足条件.

// 每个点有2个可能，获取 或者不获取

// 2 满足条件的坐标都是从小到大的， 例如  1 2 3 和 3 2  1 是同一个路径 这就不是排列组合问题了。
// 只要寻找一个就可以 index从小到大就可以 
//  */
// class Solution3
// {
// public:
//   bool canPartition(vector<int> &nums)
//   {
//     if (nums.empty())
//       return true;
//     int target = accumulate(nums.begin(), nums.end(), 0);
//     if (target % 2 != 0)
//       return false;
//     target /= 2;

//     return findSum(0, nums[0], target, nums);
//   }
//   bool findSum(int start, int sum, int target, vector<int> &nums)
//   {
//     if (sum == target)
//       return true;
//     if (sum > target || start >= nums.size())
//       return false;

//     if (true == findSum(start + 1, sum + nums[start], target, nums))
//     {
//       return true;
//     }
//     int index = start + 1;
//     //解决重复问题
//     while (index < nums.size() && nums[index] == nums[start])
//     {
//       index++;
//     }
//     //解决重复问题
//     return findSum(index, sum, target, nums);
//   }
// };

// /**
//  *
//  * 算法描述：标准的回溯法  ok
//  * 步骤 
//  * 1. 从0到n个记录中选择一个记录开始(node)
//  * 2. 如果符合条件 寻找结束
//  * 3. 如果不符合条件，剩余的n-1个记录继续寻找(edge)。 是不是很easy
//  * 符合条件根据具体的题目 这里是遍历sum（path）=target
//  * 测试用例 
//  * 1. [1,5,11,5] ---true
//  * 2. [3,3,3,4,5] ---true
//  * 2. 超出时间限制
//  *[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100]
   
//   [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,90]
//   问题：都sort，还去重了，为什么还是出错。重复元素1太多了。   used的问题
 
//  [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,90]
//   继续改进  添加sort 终于正确了
//    if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == true) {
//         continue;
//       }
//   添加后 空间运行减少2M

//  */
// class Solution1
// {
// public:
//   bool canPartition(vector<int> &nums)
//   {
//     if (nums.empty())
//       return true;
//     int target = accumulate(nums.begin(), nums.end(), 0);
//     if (target % 2 != 0)
//       return false;
//     target /= 2;
//     vector<bool> visited(nums.size(), false);
//     sort(nums.begin(), nums.end(), greater<int>());
//     // lastSum=0,路径的第一层从n个记录中任意位置开始。
//     if (nums.back() > target)
//       return false;
//     return dfs(0, 0, target, visited, nums);
//   }

//   bool dfs(int start, int lastSet, int target, vector<bool> &visited,
//            vector<int> &nums)
//   {
//     if (start > nums.size())
//     {
//       return false; // 等于是表示最后一个元素是合法的。
//     }
//     for (int i = 0; i < nums.size(); i++)
//     {
//       if (visited[i] == true)
//       {
//         continue; // used
//       }
//       if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == true)
//       {
//         continue;
//       }
//       if (lastSet + nums[i] == target)
//         return true; // 添加一个元素后 等于目标 路径找到
//       if (lastSet + nums[i] > target)
//         return false; //加一个元素后，超过目标，路径错误

//       visited[i] = true;
//       //加一个元素后，小于目标，继续寻找
//       if (true == dfs(start + 1, lastSet + nums[i], target, visited, nums))
//       {
//         return true;
//       }

//       visited[i] = false;
//     }
//     return false;
//   }
// };

// /**
//  * 算法描述：标准的回溯法 超时
//  * 步骤 
//  * 1. 从0到n个记录中选择一个记录开始(node)
//  * 2. 如果符合条件 寻找结束
//  * 3. 如果不符合条件，剩余的n-1个记录继续寻找(edge)。 是不是很easy
//  * 符合条件根据具体的题目 这里是遍历sum（path）=target
//  * 测试用例 
//  * 1. [1,5,11,5] ---true
//  * 2. [3,3,3,4,5] ---true
//  * 2. 超出时间限制
//  *[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100]
   
//   [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,90]
  
//  **/
// class Solution2
// {
// public:
//   bool canPartition(vector<int> &nums)
//   {
//     if (nums.empty())
//       return true;
//     int target = accumulate(nums.begin(), nums.end(), 0);
//     if (target % 2 != 0)
//       return false;
//     target /= 2;
//     sort(nums.begin(), nums.end(), less<int>());
//     vector<bool> visited(nums.size(), false);

//     // lastSum=0,路径的第一层从n个记录中任意位置开始。
//     return dfs(0, 0, target, visited, nums);
//   }

//   bool dfs(int level, int lastSet, int target, vector<bool> &visited,
//            vector<int> &nums)
//   {
//     if (level ==)
//     {
//     }
//     for (int i = 0; i < nums.size(); i++)
//     {
//       if (visited[i] == true)
//       {
//         continue; // used
//       }
//       if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == true)
//       {
//         continue;
//       }
//       if (lastSet + nums[i] == target)
//         return true; // 添加一个元素后 等于目标 路径找到
//       if (lastSet + nums[i] > target)
//         return false; //加一个元素后，超过目标，路径错误

//       visited[i] = true;
//       //加一个元素后，小于目标，继续寻找
//       if (true == dfs(level + 1, lastSet + nums[i], target, visited, nums))
//       {
//         return true;
//       }

//       visited[i] = false;
//     }
//     return false;
//   }
// };

// class Solution
// {
// public:
//   bool canPartition(vector<int> &nums)
//   {
//     int n = nums.size();
//     if (0 == n)
//       return true;
//     int sum = std::accumulate(nums.begin(), nums.end(), 0);
//     if (sum % 2 != 0)
//       return false;
//     sum = sum / 2;
//     vector<bool> visited(n, false);
//     return dfs(0, 0, sum, visited, nums);
//   }

//   bool dfs(int start, int sum, int target, vector<bool> &visited,
//            vector<int> &nums)
//   {
//     // exit
//     if (sum == target)
//       return true;

//     if (sum > target)
//     {
//       return false;
//     }
//     // less
//     for (int i = 0; i < nums.size(); i++)
//     {
//       if (visited[i] == true)
//       {
//         continue;
//       }
//       visited[i] = true;
//       //小技巧，当前层 计算当前累计元素
//       if (true == dfs(start + 1, sum + nums[start], target, visited, nums))
//       {
//         return true;
//       }

//       visited[i] = false;
//     }
//     return false;
//   }
// };
// @lc code=end
