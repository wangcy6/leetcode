package wcy;

public class Leetcode_378 {
     //https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60294/Solution-explained
	 public int kthSmallest(int[][] matrix, int k) {
	        int[] heap = new int[k];
	        int count = 0;
	        int start_h = 0;
	        int start_l = 0;
	        boolean is_break = false;
	        for(start_h = 0 ; start_h < matrix.length ; start_h++){
	            for(start_l = 0 ; start_l < matrix[0].length ; start_l++){
	                if(count != k){
	                    heap[count] = matrix[start_h][start_l];
	                    count++;
	                }else{
	                    is_break = true;
	                    break;
	                }
	            }
	            if(is_break){
	                break;
	            }
	        }
	        
	        to_heap(heap);
	        
	        //
	        for(int i = start_h ; i < matrix.length ; i++){
	            for(int j = start_l ; j < matrix[0].length ; j++){
	                if(matrix[i][j] < heap[0]){
	                    heap[0] = matrix[i][j];
	                    adjust_heap(heap,0);
	                }
	            }
	            start_l = 0;
	        }
	        return heap[0];
	    }
	    public void to_heap(int[] heap){
	        for(int i = (heap.length/2 - 1) ; i >= 0 ; i--){
	            adjust_heap(heap,i);
	        }
	    }
	    //ÉýÐò£¬´ó¶¥¶Ñ
	    public void adjust_heap(int[] heap,int index){
	        
	    	if((index*2 + 1) >= heap.length) return;
	        
	        int temp = index*2 + 1;
	        
	        if((index*2 + 1) < (heap.length - 1))
	        {
	            int right = heap[index*2 + 2];
	            if(heap[temp] < right){
	                temp += 1;
	            }
	        }
	        if(heap[index] < heap[temp]){
	            swap(heap,index,temp);
	            adjust_heap(heap,temp);
	        }
	    }
	    public void swap(int[] num , int i , int j){
	        int temp = num[i];
	        num[i] = num[j];
	        num[j] = temp;
	    }


	public static void main(String[] args) {
		 int[][] matrix = {
	                {1,  5,  9},
	                {10, 11, 13},
	                {12, 13, 15}
	        };
	       
		    Leetcode_378 solution = new Leetcode_378();
	        
	        System.out.println(solution.kthSmallest(matrix, 8));

	}

}
