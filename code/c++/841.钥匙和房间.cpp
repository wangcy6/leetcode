/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 *
 * https://leetcode-cn.com/problems/keys-and-rooms/description/
 *
 * algorithms
 * Medium (62.43%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    26K
 * Total Submissions: 39.8K
 * Testcase Example:  '[[1],[2],[3],[]]'
 *
 * 有 N 个房间，开始时你位于 0 号房间。每个房间有不同的号码：0，1，2，...，N-1，并且房间里可能有一些钥匙能使你进入下一个房间。
 * 
 * 在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，其中
 * N = rooms.length。 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。
 * 
 * 最初，除 0 号房间外的其余所有房间都被锁住。
 * 
 * 你可以自由地在房间之间来回走动。
 * 
 * 如果能进入每个房间返回 true，否则返回 false。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: [[1],[2],[3],[]]
 * 输出: true
 * 解释:  
 * 我们从 0 号房间开始，拿到钥匙 1。
 * 之后我们去 1 号房间，拿到钥匙 2。
 * 然后我们去 2 号房间，拿到钥匙 3。
 * 最后我们去了 3 号房间。
 * 由于我们能够进入每个房间，我们返回 true。
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[1,3],[3,0,1],[2],[0]]
 * 输出：false
 * 解释：我们不能进入 2 号房间。
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= rooms.length <= 1000
 * 0 <= rooms[i].length <= 1000
 * 所有房间中的钥匙数量总计不超过 3000。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //利用队列对图进行 广度优先搜索(bfs)
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int number = rooms.size();
        vector<bool> visited(number, flase); //标记n个房间
        visited[0] = true; //通过第一个节点。判断各个房间所连成的有向图，是否存在孤岛，如果有孤岛，说明不用访问所有的房间。
        // 0 号房间外的其余所有房间都被锁住

        queue<int> data; //控制遍历顺序。
        data.push(0); // 0 号房间

        while (data.empty() == false) {

            //出队列 入队列操作
            int index = data.top();
            data.pop();

            vector<int> keys = rooms[index]; //获取第i房间钥匙,插入data中记录已经访问过

            for (int key : keys) {

                data.push(key);
            }

            //直接访问其他节点
        }
    }
};
// @lc code=end
