package wcy;
/**
 *  
 * @author wangchuanyi
 * tag:二分查找 ;分治
 */
public class Leetcode_240 {

	
	    private int[][] matrix;
	    private int target;
	    /**
	     *   zone 1      zone 2
			*  *  *  * | *  *  *  *
			*  *  *  * | *  *  *  *
			*  *  *  * | *  *  *  *
			*  *  *  * | *  *  *  *
			-----------------------
			*  *  *  * | *  *  *  *
			*  *  *  * | *  *  *  *
			*  *  *  * | *  *  *  *
			*  *  *  * | *  *  *  *
			  zone 3      zone 4
	     * @param matrix
	     * @param target
	     * @return
	     */
	    public boolean searchMatrix3(int[][] matrix, int target) {
	        int m = matrix.length;
	        if(m<1) return false;
	        int n = matrix[0].length;
	        
	        return searchMatrix3(matrix, new int[]{0,0}, new int[]{m-1, n-1}, target);
	    }

	    private boolean searchMatrix3(int[][] matrix, int[] upperLeft, int[] lowerRight, int target) {
	    	if(upperLeft[0]>lowerRight[0] || upperLeft[1]>lowerRight[1]
	    			|| lowerRight[0]>=matrix.length || lowerRight[1]>=matrix[0].length) 
	    		return false;
	    	if(lowerRight[0]-upperLeft[0]==0 && lowerRight[1]-upperLeft[1]==0)
	    		return matrix[upperLeft[0]][upperLeft[1]] == target;
	    	int rowMid = (upperLeft[0] + lowerRight[0]) >> 1;
	    	int colMid = (upperLeft[1] + lowerRight[1]) >> 1;
	    	int diff = matrix[rowMid][colMid] - target;
	    	if(diff > 0) {
	    		return searchMatrix3(matrix, upperLeft, new int[]{rowMid, colMid}, target)
	    				|| searchMatrix3(matrix, new int[]{upperLeft[0],colMid+1}, new int[]{rowMid, lowerRight[1]}, target)
	    				|| searchMatrix3(matrix, new int[]{rowMid+1,upperLeft[1]}, new int[]{lowerRight[0], colMid}, target);
	    	}
	    	else if(diff < 0) {
	     		return searchMatrix3(matrix, new int[]{upperLeft[0], colMid+1}, new int[]{rowMid, lowerRight[1]}, target)
	    				|| searchMatrix3(matrix, new int[]{rowMid+1, upperLeft[1]}, new int[]{lowerRight[0], colMid}, target)
	    				|| searchMatrix3(matrix, new int[]{rowMid+1, colMid+1}, lowerRight, target);
	    	}
	    	else return true;
	    }
	    
        //https://leetcode.com/problems/search-a-2d-matrix-ii/discuss/66147/*Java*-an-easy-to-understand-divide-and-conquer-method
	    private boolean searchRec1(int left, int up, int right, int down) {
	        // this submatrix has no height or no width.
	        if (left > right || up > down) {
	            return false;
	        // `target` is already larger than the largest element or smaller
	        // than the smallest element in this submatrix.
	        } else if (target < matrix[up][left] || target > matrix[down][right]) {
	            return false;
	        }

	        int mid = left + (right-left)/2;

	        // Locate `row` such that matrix[row-1][mid] < target < matrix[row][mid]
	        int row = up;
	        while (row <= down && matrix[row][mid] <= target) {
	            if (matrix[row][mid] == target) {
	                return true;
	            }
	            row++;
	        }

	        return searchRec1(left, row, mid-1, down) || searchRec1(mid+1, up, right, row-1);
	    }

	    public boolean searchMatrix1(int[][] mat, int targ) {
	        // cache input values in object to avoid passing them unnecessarily
	        // to `searchRec`
	        matrix = mat;
	        target = targ;

	        // an empty matrix obviously does not contain `target`
	        if (matrix == null || matrix.length == 0) {
	            return false;
	        }

	        return searchRec1(0, 0, matrix[0].length-1, matrix.length-1);
	    }


	/**
	 *  https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
	 * @param matrix
	 * @param target
	 * @return
	 */
	public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        if (rows == 0) {
            return false;
        }
        int cols = matrix[0].length;
        if (cols == 0) {
            return false;
        }


        // 起点：左下角
        int x = rows - 1;
        int y = 0;
        // 不越界的条件是：行大于等于 0，列小于等于 cols - 1
        while (x >= 0 && y < cols) {
            // 打开注释，可以用于调试的代码
            // System.out.println("沿途走过的数字：" + matrix[x][y]);
            if (matrix[x][y] > target) {
                x--;
            } else if (matrix[x][y] < target) {
                y++;
            } else {
                return true;
            }
        }
        /**
         * 总结出“搜索”的规律是：

				如果当前数比目标元素小，当前列就不可能存在目标值，“指针”就向右移一格（纵坐标加 1）；
				如果当前数比目标元素大，当前行就不可能存在目标值，“指针”就向上移一格（横坐标减 1）
         */
        return false;
    }

    public static void main(String[] args) {
        int[][] matrix = {
                {1, 4, 7, 11, 15},
                {2, 5, 8, 12, 19},
                {3, 6, 9, 16, 22},
                {10, 13, 14, 17, 24},
                {18, 21, 23, 26, 30}
        };
        int target = 12;
        Leetcode_240 solution = new Leetcode_240();
        boolean searchMatrix = solution.searchMatrix(matrix, target);
        System.out.println(searchMatrix);
       
        System.out.println(solution.searchMatrix1(matrix, target));
       
       System.out.println(solution.searchMatrix3(matrix, target));

    }


}
