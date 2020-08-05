/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode-cn.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (51.59%)
 * Likes:    483
 * Dislikes: 0
 * Total Accepted:    58.8K
 * Total Submissions: 110.5K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
 * 
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
 * 
 * 给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 2, [[1,0]] 
 * 输出: true
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
 * 
 * 示例 2:
 * 
 * 输入: 2, [[1,0],[0,1]]
 * 输出: false
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。
 * 你可以假定输入的先决条件中没有重复的边。
 * 1 <= numCourses <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
    }
};
// @lc code=end

class Solution1
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {

        graph_ = vector<vector<int>>(numCourses);

        for (const auto &p : prerequisites)
            graph_[p.first].push_back(p.second);

        // states: 0 = unkonwn, 1 == visiting, 2 = visited
        vector<int> v(numCourses, 0);

        for (int i = 0; i < numCourses; ++i)
            if (dfs(i, v))
                return false;

        return true;
    }

private:
    vector<vector<int>> graph_;
    bool dfs(int cur, vector<int> &v)
    {
        if (v[cur] == 1)
            return true;
        if (v[cur] == 2)
            return false;

        v[cur] = 1;

        for (const int t : graph_[cur])
            if (dfs(t, v))
                return true;

        v[cur] = 2;

        return false;
    }
};
class Solution2
{
public:
    vector<int> visit;
    bool dfs(int v, vector<vector<int>> &g)
    {
        if (g[v].size() == 0) //没相邻的节点了，返回true
            return true;

        if (visit[v] == -1) //走这节点没环，返回true
            return true;

        if (visit[v] == 1) //被标记过了，存在环，返回false
            return false;

        visit[v] = 1; //标记

        bool res = true;
        for (int i = 0; i < g[v].size(); i++) //访问v节点的所有相连接的节点，对于每个节点都进行dfs
        {
            res = dfs(g[v][i], g);
            if (res == false)
                break;
        }
        visit[v] = -1; //回溯时设置visit为-1
        return res;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> g(numCourses);
        visit = vector<int>(numCourses + 1, 0);
        //建立有向邻接表
        for (int i = 0; i < prerequisites.size(); i++)
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);

        bool res = true;
        for (int i = 0; i < numCourses; i++) //对每个节点进行dfs（深度优先遍历）
            for (int j = 0; j < g[i].size(); j++)
            {
                res = dfs(g[i][j], g);
                if (res == false)
                    return res;
            }
        return res;
    }
};

// class Solution3
// {
// public:
//     bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
//     {
//         int m = prerequisites.size();
//         vector<int> vec1(numCourses, 0);      //存储入度
//         vector<vector<int>> vec2(numCourses); //存储每个课程的邻接节点
//         for (vector<int> pre : prerequisites)
//         {
//             vec1[pre[1]]++;
//             vec2[pre[0]].push_back(pre[1]);
//         }
//         //用广度优先搜索
//         queue<int> q;
//         //入队入度为 0 的节点
//         for (int i = 0; i < numCourses; i++)
//         {
//             if (vec1[i] == 0)
//                 q.push(i);
//         }
//         int cnt = 0; //用来计数遍历到的节点
//         while (!q.empty())
//         {
//             for (int i = q.size(); i > 0; i--)
//             {
//                 int cur = q.front();
//                 q.pop();
//                 cnt++;
//                 //遍历当前节点的邻接节点，入度减一
//                 for (int course : vec2[cur])
//                 {
//                     //如果入度变为 0 入队
//                     if (--vec1[course] == 0)
//                         q.push(course);
//                 }
//             }
//         }
//         return cnt == numCourses;
//     }
// };
// class Solution4 {
//     public boolean canFinish(int numCourses, int[][] prerequisites) {//numCourses个结点的有向图
//         //n条边
//         int n = prerequisites.length;
//         //邻接表
//         ArrayList<Integer>[] adjacencyList = new ArrayList[numCourses];
//         //入度数组，inDegree[i]的值表示节点i的入度
//         int[] inDegree = new int[numCourses];
//         //先由边的集合构建邻接表
//         for(int i = 0; i < numCourses; i++) {
//             adjacencyList[i] = new ArrayList<Integer>();
//         }
//         for(int[] p : prerequisites) {
//             adjacencyList[p[1]].add(p[0]);
//             inDegree[p[0]]++;
//         }
//         //拓扑排序判断是不是DAG
//         return topologicalSort(adjacencyList,inDegree,numCourses);
//     }
//     private boolean topologicalSort(ArrayList<Integer> [] adjacencyList,int [] inDegree,int n){//邻接表和入度数组
//         int cnt = 0; // 保存能取出的结点数目
//         // 定义队列保存入度为零的结点
//         Queue<Integer> queue = new LinkedList<Integer>();
//         for(int i = 0; i < n; i++) {
//             // 入度为零的结点入队
//             if(inDegree[i] == 0) {
//                 queue.offer(i);
//             }
//         }
//         // 取出入度为零的结点，更新其余结点的入度
//         while(!queue.isEmpty()) {
//             int i = queue.poll(); // 取出队头元素
//             cnt++; // 计数加一
//             for(int child_of_i : adjacencyList[i]) {
//                 inDegree[child_of_i]--;
//                 if(inDegree[child_of_i] == 0) {
//                 queue.offer(child_of_i);
//                 }
//             }
//         }
//         return cnt == n;
//     }
// }

//https://leetcode-cn.com/problems/course-schedule/solution/bao-mu-shi-ti-jie-shou-ba-shou-da-tong-tuo-bu-pai-/