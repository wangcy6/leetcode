#include "stdio.h"



/**
步骤描述：
1 递归遍历数组。 如果是升序 返回最小值，
2.如果非升序，继续递归 递归变化条件去中间值
3 判断 折半拆分后数据那个最小
测试用例：
   因为是根据索引判断，跟具体数字没有任何关系 
时间复杂度：
	time: lg（n）
	space o(n)
	执行用时: 8 ms, 在Find Minimum in Rotated Sorted Array的C提交中击败了24.43% 的用户
	内存消耗: 4.1 MB, 在Find Minimum in Rotated Sorted Array的C提交中击败了0.00% 的用户
**/
int findMin(int* nums, int numsSize) {
 
  return find_min(nums,0,numsSize-1); 	
}

int find_min(int* nums, int start,int end)
{   
	//如果数据很少，直接判断
	if(end-start<=1)
	{
		return  nums[start]<nums[end]?nums[start]:nums[end];
	}
     //一部分是升序
	if(nums[end]>nums[start])
	{
      return nums[start];
	}
	//一部分不是升序，继续递归
    int mid=(start+end)/2;
	int leftMin=find_min(nums,start,mid);
	int rightMin=find_min(nums,mid+1,end);

	return leftMin<rightMin?leftMin:rightMin;

}



/**
步骤描述：
	顺序遍历发现最小值

测试用例：
	因为是顺序遍历 跟具体数字没有任何关系
时间复杂度：
	执行用时: 8 ms,  在Find Minimum in Rotated Sorted Array的C提交中击败了24.43% 的用户
	内存消耗: 4.1 MB,在Find Minimum in Rotated Sorted Array的C提交中击败了0.00% 的用户

**/
int findMin1(int* nums, int numsSize) {
 
 int min=nums[0];
 for(int i=1;i<numsSize;i++)
 {
	 if(nums[i]<min)
	 {
		 min=nums[i];
	 }
 }	 
 return min;	
}

int main( int argc, char *argv[] ) 
{
    
    return 0;
}