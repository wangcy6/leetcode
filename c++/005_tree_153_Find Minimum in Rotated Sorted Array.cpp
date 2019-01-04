class Solution {
public:
    
    /**
	Time  complexity:T(n) = O(1) + T(n/2) = O(logn)
	Space complexity:o(1)
	查找逻辑跟索引位置切分的，根数据大小没关系，数据全部相等，也没有关系
	**/
    int find_min(vector<int>&nums,int start,int end){
        
        if((end-start)<=1) 
        {
          return min(nums[start],nums[end]);    
        }
        
        if (nums[end]>nums[start]){
            return nums[start];
        }
        
        int mid=(start+end)/2;
        
        int left=find_min(nums,start,mid);
        int right=find_min(nums,mid+1,end);
        
        return min(left,right);
        
    }
	int findMin(vector<int>& nums) {
        
        return find_min(nums,0,nums.size()-1);
    }
};