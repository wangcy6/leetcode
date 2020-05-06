package wcy;

public class Leetcode_79 {
	
	  public boolean exist(char[][] board, String word) {
	    if (board == null || board.length == 0 || board[0].length == 0
	        || word == null || word.length() == 0) return true;
	
	    int rows = board.length;
	    int cols = board[0].length;
	    
	    for (int r = 0; r < rows; r++) {
	      for (int c = 0; c < cols; c++) {
	        // scan board, start with word first character 
	        if (board[r][c] == word.charAt(0)) {
	          if (helper(board, word, r, c, 0)) {
	            return true;
	          }
	        }
	      }
	    }
	    return false;
	  }

	  private boolean isValid(char[][] board, int r, int c) {
	    return r >= 0 && r < board.length && c >= 0 && c < board[0].length;
	  }
	  private boolean helper(char[][] board, String word, int r, int c, int start) {
	    // already match word all characters, return true
	    if (start == word.length()) return true;
	    if (!isValid(board, r, c) ||
	        board[r][c] != word.charAt(start)) return false;
	    // mark visited
	    board[r][c] = '*';
	    
	    boolean res = helper(board, word, r + 1, c, start + 1)
	        ||  helper(board, word, r, c + 1, start + 1)
	        ||  helper(board, word, r - 1, c, start + 1)
	        ||  helper(board, word, r, c - 1, start + 1);
	    // backtracking to start position
	    
	    board[r][c] = word.charAt(start);//任意点都可能回溯到该节点，因此使用完毕，必须重新设置回去。
	    
	    return res;
	  }
}
