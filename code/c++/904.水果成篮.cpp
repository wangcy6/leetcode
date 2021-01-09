/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 *
 * https://leetcode-cn.com/problems/fruit-into-baskets/description/
 *
 * algorithms
 * Medium (42.62%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    9.6K
 * Total Submissions: 22.6K
 * Testcase Example:  '[1,2,1]'
 *
 * 在一排树中，第 i 棵树产生 tree[i] 型的水果。
 * 你可以从你选择的任何树开始，然后重复执行以下步骤：
 * 
 * 
 * 把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
 * 移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
 * 
 * 
 * 请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。
 * 
 * 你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
 * 
 * 用这个程序你能收集的水果树的最大总量是多少？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,1]
 * 输出：3
 * 解释：我们可以收集 [1,2,1]。
 * 
 * 
 * 示例 2：
 * 
 * 输入：[0,1,2,2]
 * 输出：3
 * 解释：我们可以收集 [1,2,2]
 * 如果我们从第一棵树开始，我们将只能收集到 [0, 1]。
 * 
 * 
 * 示例 3：
 * 
 * 输入：[1,2,3,2,2]
 * 输出：4
 * 解释：我们可以收集 [2,3,2,2]
 * 如果我们从第一棵树开始，我们将只能收集到 [1, 2]。
 * 
 * 
 * 示例 4：
 * 
 * 输入：[3,3,3,1,2,1,1,2,3,3,4]
 * 输出：5
 * 解释：我们可以收集 [1,2,1,1,2]
 * 如果我们从第一棵树或第八棵树开始，我们将只能收集到 4 棵水果树。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= tree.length <= 40000
 * 0 <= tree[i] < tree.length
 * https://leetcode-cn.com/problems/fruit-into-baskets/solution/xi-fa-dai-ni-xue-suan-fa-yi-ci-gao-ding-qian-zhu-3/
 * 
 */

// @lc code=start
class Solution {
public:
    //用[begin,end]  维持一个窗口，窗口确保连续性，但是只允许存在2个元素类型

    //如果窗口的元素种类大于2个，移动begin位置。
    int totalFruit(vector<int>& tree)
    {
        //虽然每个篮子可以放无限水果，但是只一个篮子只能放一个类型的水果，2个篮子只能放2个类型的水果

        //直接排序获取重复最多的2个类型不行，要求这个2元素重复连续(移动到当前树右侧的下一棵树)

        //收集的水果树的最大总量 不是水果大小相加。数组中的多少个记录

        //我第一想到暴力破解，从任意位置遍历2层循环，判断是否2个类型，不然结束。

        //类比 无重复字符的最长子串 [begin  i  end] 这个是无重复字符，然后舍去办法。但是hash并没有发生改变，窗口要求最大

        //你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
        //0 <= tree[i] < 40000
        //数组改为hash存储。

        // 难点：如何统计i出现次数超过2中类
        // 输入：[3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4]
        // 3 --3  1 --1  2 ---1

        //如果删除呢 ？？？
        // unordered_map<int, int> map; //不是放入40000，最多三个，可以用数组表示

        unordered_map<int, int> hash; //

        int begin = 0; //窗口内只能包含2个种水果
        int end = 0; //窗口内只能包含2个种水果
        int ret = 0;
        while (end < tree.size()) {

            hash[tree[end]]++;
            //规则1 判断是否能放入篮子,如果超过2个直接删除
            //如何删除一个key，直接删除可以吗?可以，但是这里考虑移动问题
            // if (hash.size() > 2) {
            //     int step = hash[tree[begin]];
            //     hash.erase(tree[begin]);
            //     begin += step;
            // }
            while (hash.size() > 2) {
                if (--hash[tree[begin]] == 0) {
                    hash.erase(tree[begin]);
                }
                begin++;
                ////[1,0,1,4,1,4,1,2,3]   5
                //这里结果肯定是 保留相邻的1 去掉0 ，
                // 特点：2个重复的1 1个重复的0
                //这是最烧脑地方。
            }
            //我的是固定的，这个是变化的
            ret = max(ret, end - begin + 1);
            end++;
        }

        return ret;
    }
};
// @lc code=end
