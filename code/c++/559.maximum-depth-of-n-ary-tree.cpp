/*
 * https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/submissions/
 **/
class Solution {
public:
  int maxDepth(Node *root) {
    if (NULL == root) {
      return 0;
    }
    if (root->children.size() == 0) {
      return 1; //提升4ms，不需要做for循环判断
    }

    int depth = 0;
    for (int i = 0; i < root->children.size(); i++) {
      depth =
          max(depth,
              maxDepth(root->children[i])); //选择最大的一个，这里没有+1这动作
    }

    return depth + 1;
  }
};

class Solution_DFS {
public:
  int maxDepth(Node *root) {
    if (NULL == root) {
      return 0;
    }
    std::stack<pair<Node *, int>> mystack;    //深度遍历特点
    mystack.push(pair<Node *, int>(root, 1)); //从上到下传递深度
    int max_depth = 0; //统计从root节点到leaf节点之间最大距离

    while (!mystack.empty()) {
      Node *tempNode = mystack.top().first;
      int depth = mystack.top().second; //出栈 
      mystack.pop();

      //从左到右遍历,空节点不入栈
      for (Node *it : tempNode->children) {
        if (it) {
          mystack.push(pair<Node *, int>(it, depth + 1)); //入栈
          //         A (3)
          //    B(4)      C (4)
        }
      }
      // if (tempNode->children.size() ==0 ) { 添加 size 判断增加20ms的时间
      max_depth = max(max_depth, depth);
      //}
    }
    return max_depth;
  }
};

class Solution_BFS {
public:
  int maxDepth(Node *root) {
    if (!root)
      return 0;
    queue<Node *> queue;
    queue.push(root);
    int max_depth = 0;
    while (!queue.empty()) {
      max_depth++;
      //记录当前层有size个节点，然后删除前面size个节点数值
      for (int size = queue.size(); size; size--) {
        Node *curr = queue.front();
        queue.pop();
        for (Node *it : curr->children)
          queue.push(it);
      }
    }
    return max_depth;
  }
};
