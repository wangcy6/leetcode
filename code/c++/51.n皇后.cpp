/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51]
 */

// @lc code=start
class Solution {
public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> nQueens(n, std::string(n, '.'));
    solveNQueens(res, nQueens, 0, n);
    return res;
  }

private:
  void solveNQueens(std::vector<std::vector<std::string>> &res,
                    std::vector<std::string> &nQueens, int row, int &n) {
    if (row == n) {
      res.push_back(nQueens);
      return;
    }
    for (int col = 0; col != n; ++col)
      if (isValid(nQueens, row, col, n)) {
        nQueens[row][col] = 'Q';
        solveNQueens(res, nQueens, row + 1, n);
        nQueens[row][col] = '.';
      }
  }
  bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
    // check if the column had a queen before.
    for (int i = 0; i != row; ++i)
      if (nQueens[i][col] == 'Q')
        return false;
    // check if the 45° diagonal had a queen before.
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
      if (nQueens[i][j] == 'Q')
        return false;
    // check if the 135° diagonal had a queen before.
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
      if (nQueens[i][j] == 'Q')
        return false;
    return true;
  }
};

class Solution2 {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int> queenCol(n, -1);
    helper(0, queenCol, res);
    return res;
  }
  void helper(int curRow, vector<int> &queenCol, vector<vector<string>> &res) {
    int n = queenCol.size();
    if (curRow == n) {
      vector<string> out(n, string(n, '.'));
      for (int i = 0; i < n; ++i) {
        out[i][queenCol[i]] = 'Q';
      }
      res.push_back(out);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (isValid(queenCol, curRow, i)) {
        queenCol[curRow] = i;
        helper(curRow + 1, queenCol, res);
        queenCol[curRow] = -1;
      }
    }
  }
  bool isValid(vector<int> &queenCol, int row, int col) {
    for (int i = 0; i < row; ++i) {
      if (col == queenCol[i] || abs(row - i) == abs(col - queenCol[i]))
        return false;
    }
    return true;
  }
};
// @lc code=end
