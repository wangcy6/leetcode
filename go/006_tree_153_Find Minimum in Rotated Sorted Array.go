package main /**
154. 寻找旋转排序数组中的最小值 II
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
请找出其中最小的元素。
注意数组中可能存在重复的元素。
输入: [2,2,2,0,1]
输出: 0
**/

/**
162. Find Peak Element
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
https://leetcode.com/problems/find-peak-element/

峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞。
https://leetcode-cn.com/problems/find-peak-element/description/

**/

func findPeakElement(nums []int) int {
	begin := 0
	end := len(nums) - 1

	for (end - begin) > 1 {
		mid := (begin + end) / 2
		if nums[mid-1] < nums[mid] {
			begin = mid

		} else if nums[mid-1] > nums[mid] {

			end = mid - 1
		} else {
			//即先增后减的序列
			if nums[mid] >= nums[begin] {
				begin++
			}
		}
	}
	if nums[end] >= nums[begin] {
		return end
	} else {
		return begin
	}
}

/**
//https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/description/
585. 山脉序列中的最大值
描述
给n个整数的山脉数组，即先增后减的序列，找到山顶（最大值）
期望:请找出最大值
拦路虎：
1。通过数组的边界无法判断整个数组连续性，
   例如[123] 3>1是升序，[1 2 10 30 6 5] 5>1不是升序
   思路被阻塞中了，无法进行下去？ game over
2.  等2个元素相等的时候根本 不知道如何移动。
   [1,2,10,10,10,10] [1,1,1,1,1,1,0]

测试
1. 如果是降序 第一数字就是最大值 [10, 9, 8, 7]
2. 如果是升序 最后一个数字就是最大值[1, 2, 4, 8]
3. 如果全部有升序，降序 一定有最大值 [1, 2, 4, 8, 6, 3]
4 [1, 10, 10, 10, 2, 1] [1, 1, 1, 1, 1, 10]

描述：
假设nums[i] 其中一个元素，那么nums[i-1] 一定存在 至少2个元素
1.
2.
3.

耗时
其他建议：
https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
面试题目，来自G。首先，这道题目一定可以有一个答案。
(1)如果数组先增大再减小，一定有答案。
(2)如果数组单调递增，最后一个元素就是答案。
(3)如果数组单调递简，第一个元素就是答案。
(4)如果数组全部都一样，任何一个元素都是答案，更极端地，如果数组只有一个元素，那么这唯一的元素就是答案。
(5)如果数组出现了几个峰值，那么任何一个峰值都是答案。
---------------------
作者：feliciafay
来源：CSDN
原文：https://blog.csdn.net/feliciafay/article/details/20586551
版权声明：本文为博主原创文章，转载请附上博文链接！
---------------------
 * @param nums: a mountain sequence which increase firstly and then decrease
 * @return: then mountain top
*/
func mountainSequence(nums []int) int {
	// write your code here

	begin := 0
	end := len(nums) - 1

	for (end - begin) > 1 {
		mid := (begin + end) / 2
		if nums[mid-1] < nums[mid] {
			begin = mid

		} else if nums[mid-1] > nums[mid] {

			end = mid - 1
		} else {
			//即先增后减的序列
			if nums[mid] >= nums[begin] {
				begin++
			}
		}
	}

	return max(nums[end], nums[begin])

}

/** 第一题 find-minimum-in-rotated-sorted-array
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
153. 寻找旋转排序数组中的最小值
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
请找出其中最小的元素。

期望:请找出其中最小的元素
拦路虎：
1. 如果是完全升序  第一数字就是 ，
   旋转数值是升序（相邻的元素都是递增）， 根本不知道抄那个方向移动？炸锅了。
   肯定没有那么容易赛。
2. 我想通过观察特点 怪点(2边元素都大于它)就是最小元素这个没问题，，需要至少4个元素判断 很容易越界。 i++。i--都比较复杂了
   还是回到问题1，
比较点【相邻元素】【边界元素】【变化点】都有缺陷
过程描述
随便寻找一个数字i,判断nums[i]是否为最小值
1 如果nums[i]>nums[end]，说明nums[i]不是最小元素 ，最小元素在后面 ---> i+1
2.如哦nums[i]<nums[end],nums[end]不是最小元素，后面元素比当前元素i还大，这是升序 最小元素在前面  <---- i-1
  但是最后一个元素情况下 nums[end]可能是最小元素 i（这个)
3 如果 nums[i]==nums[end] 相等的话就舍去一个呀（这个遗漏了）
4 折半查找直到循环结束，范围缩小到最后一个元素 （这个不是一般能想到的，讨巧了，时候才知道，不是通用的方法 if 判断 watch结果是否越界）

测试：
1 int{1, 2, 3, 4, 5, 6} 如果升序不需要排序 上面规则不在查找了 ok
2 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  ok
3.{3, 3, 1, 3} 完全错误的是
缺点：
1. 通过数字的大小有关系,
 跟数字的内容有关系，需要很复杂的逻辑判断。 有点不是很好
 find-minimum-in-rotated-sorted-array-ii case3的时候我代码完全不对了
2. 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 性能o(n)




case1 寻找不到怎么办
别人的答案：
https://www.youtube.com/watch?v=P4r7mF1Jd50&t=3s
http://zxi.mytechroad.com/blog/divide-and-conquer/leetcode-153-find-minimum-in-rotated-sorted-array/
！！！！！！！！！
折半查找没有问题，但是元素比较出现了问题，无论怎么比较都不对，比较元素这个思路是错误的


**/
func findMin2(nums []int) int {
	begin := 0
	end := len(nums) - 1
	mid := 0
	if nums[end] > nums[begin] {
		//fmt.Println("sort array", nums[begin])
		return nums[begin]
	}
	for begin < end {
		mid = (begin + end) / 2
		if nums[end] < nums[mid] {
			begin = mid + 1 //排除nums[mid]不是最小元素,最小元素在后面
		} else if nums[end] > nums[mid] {
			end = mid
		} else {
			end--
		}

		//fmt.Println(begin, end, mid)
	}
	return nums[begin]

}

/**
func main() {

	//data := []int{1, 2, 3, 4, 5, 6}
	//data := []int{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	//data := []int{3, 3, 1, 3}
	//fmt.Println(data, "min=1")
	//fmt.Println(findMin(data))
	//data := []int{1}
	//fmt.Println(findMin1(data))

}**/
