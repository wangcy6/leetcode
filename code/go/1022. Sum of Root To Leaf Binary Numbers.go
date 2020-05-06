// 1022. Sum of Root To Leaf Binary Numbers.go
package main

/**
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.
For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary,
which is 13.
For all leaves in the tree,
consider the numbers represented by the path from the root to that leaf.
Return the sum of these numbers.
1 --1=1
11--1*2+1=3
111--3*2+1=7//4 2 1
1111---7*2+1=15 //8 4 2 1
**/
func sumRootToLeaf(root *TreeNode) int {
	total := 0
	path := 0
	sum_root_leaf(root, path, &total)
	return total
}

func sum_root_leaf(root *TreeNode, path int, total *int) {
	if root == nil {
		return
	}
	//左移
	path = path<<1 + root.Val

	if root.Left == nil && root.Right == nil {
		*total += path
		return
	}
	sum_root_leaf(root.Left, path, total)
	sum_root_leaf(root.Right, path, total)
}

/**
Given a binary tree and a sum,
find all root-to-leaf paths where each path's sum equals the given sum.
Note: A leaf is a node with no children.
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(root, res, tmp, sum, 0);
        return res;
    }
    void dfs(TreeNode* root, vector<vector<int>>& res, vector<int> tmp, int sum, int cursum){
        if(!root) return;
        tmp.push_back(root->val);
        if(!root->left && !root->right && (cursum + root->val == sum)) {
            res.push_back(tmp);
            return;
        }
        if(root->left) dfs(root->left, res, tmp, sum, cursum + root->val);
        if(root->right) dfs(root->right, res, tmp, sum, cursum + root->val);
    }
};
**/

//字符串中的最大回文子串长度
/**
class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() < 2) {
            return s;
        }

        int length = s.length();

        boolean[][] isPalindrome = new boolean[length][length];

        int left = 0;
        int right = 0;

        for (int j = 1; j < length; j++) {
            for (int i = 0; i < j; i++) {
                boolean isInnerWordPalindrome = isPalindrome[i + 1][j - 1] || j - i <= 2;

                if (s.charAt(i) == s.charAt(j) && isInnerWordPalindrome) {
                    isPalindrome[i][j] = true;

                    if (j - i > right - left) {
                        left = i;
                        right = j;
                    }
                }
            }
        }

        return s.substring(left, right + 1);
    }
}
**/
