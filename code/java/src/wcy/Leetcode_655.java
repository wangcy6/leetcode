package wcy;

import java.util.ArrayList;
import java.util.List;
import java.lang.Math;

public class Leetcode_655 {

	public List<List<String>> printTree(TreeNode root) {
		// 1.求出root的高度
		int rows = getHeight(root);
		// 2.求出输出List的宽度
		int cols = (int) (Math.pow(2.0, rows) - 1);

		// 对结果集初始化
		List<List<String>> res = new ArrayList<>(rows); // vector

		for (int i = 0; i < rows; i++) {
			List<String> list = new ArrayList<>();
			for (int j = 0; j < cols; j++) {
				list.add("");
			}
			res.add(list);
		}
		// 3.前序遍历，首先在结果集中填充左子树，然后填充右子树
		dfs(root, 0, 0, cols - 1, res);
		return res;

	}

	private void dfs(TreeNode root, int level, int start, int end, List<List<String>> res) {

		if (root == null || start > end) {
			return;
		}

		int mid = (start + end) / 2;

		res.get(level).set(mid, Integer.toString(root.val));
		
		//递归打印左子树
		dfs(root.left,level+1,start,mid-1,res);
		//递归打印右子树
		dfs(root.right,level+1,mid+1,end,res);
		
		

	}

	private int getHeight(TreeNode root) {
		if (root == null) {
			return 0;
		}

		return Math.max(getHeight(root.left), getHeight(root.right)) + 1;
	}

}
