/**
 * https://www.lintcode.com/problem/meeting-rooms/description
 * 描述
  给定一系列的会议时间间隔，包括起始和结束时间[[s1,e1]，[s2,e2]，…(si < ei)，
  确定一个人是否可以参加所有会议
  注意事项
(0,8),(8,10)在8这这一时刻不冲突
样例1

输入: intervals = [(0,30),(5,10),(15,20)]
输出: false
解释:
(0,30), (5,10) 和 (0,30),(15,20) 这两对会议会冲突
样例2

输入: intervals = [(5,8),(9,15)]
输出: true
解释:
这两个时间段不会冲突

思路1 ：如果实现all会议都不冲突，用最笨方法，每个会议和其他会议比较 o(n2)

思路2 ：虽然end时间不清楚，但是start是清楚的，根据start排序，和相邻的比较，
        1 2 3 4 5 6 7  4不用和全部比较，只要和3和5比较就知道答案了。 
        需要依赖当前元素和上一个元素不冲突的元素。
 */

/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
  /**
   * @param intervals: an array of meeting time intervals
   * @return: if a person could attend all meetings
   */
  bool canAttendMeetings(vector<Interval> &intervals) {
    // Write your code here
    vector<Interval> resut;
    if (intervals.size() == 0) {
      return true;
    }
    sort(
        intervals.begin(), intervals.end(),
        [](const Interval &a, const Interval &b) { return a.start < b.start; });
    resut.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
      Interval temp = resut.back();
      if (intervals[i].start < temp.end) {
        return false;
      } else {
        //没有冲突 相等的不算
        resut.push_back(intervals[i]);
      }
    }
    return true;
  }
};
/**
 * 找到所需的最小的会议室数量。
Example 1:
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2

{30} 30>5  false
{10,30} 10<15 true
{15 30}

Example 2:
Input: [[7,10],[2,4]]
Output: 1
 */
class Solution {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto interval : intervals) {
      if (!q.empty() && q.top() <= interval[0]) {
        q.pop();
      }
      q.push(interval[1]);
    }
    return q.size();
  }
};