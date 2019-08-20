package main

import "fmt"

/**
1 题目：
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
注意事项：您可以假定该字符串只包含小写字母
案例:
s = "leetcode"
返回 0.
s = "loveleetcode",
返回 2.

不遍历完毕 根本不能知道，那个是不重复的字符

2 描述：
method1 2次循环遍历
1 当前字母 和后续字母比较 如果有相同的 该字母不是 ，如果没有就是
2 如果都重复，最后返回-1
	time：o(n2)
	space:o(1)
缺点：
 该算法 根本不正确，如果都重复，最后一个字母，和以前的数字进行比较呀 aa

题目理解有问题,第一个不重复的字符 ,只要和后面不相同，然后就是第一个了，减少循环次数。
abbc 第一个b 和第二个b能比较， 第二个b谁比较呀？


method2
	 time：o(n)
	 数值访问是o(1)
	 2个for是不是内嵌
	space:o(n)

Q1 存储结构 为不map 或者unorder_map
A1 因为时间复杂度O(1) unorder_map  o(1)-o(n)  map o(logn)


3实现时间：用最笨的方法还没有些对呢

	25分钟+25分钟+25分钟+25分钟+25分钟=(85分钟)
	25分钟+25分钟+25分钟+25分钟+25分钟=(85分钟)
	你在干什么 ，为什么迁移bitmap上去了。
**/

func firstUniqChar(s string) int {
	n := len(s)
	if n == 0 {
		return -1
	}
	if n == 1 {
		return 0
	}
	dp := make([]int, 26)

	for i := 0; i < n; i++ {
		dp[s[i]-'a']++

	}
	for i := 0; i < n; i++ {
		if dp[s[i]-'a'] == 1 {
			return i
		}

	}
	return -1

}
func firstUniqChar1(s string) int {

	n := len(s)
	if n == 1 {
		return 0
	}
	var flag bool
	for i := 0; i < n; i++ {
		flag = false
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				fmt.Println(i, j, s[i], s[j])
				flag = true
				break //有相同的
			}
		}
		//最后一个字母不能作为判断
		if flag == false && i < n-1 {
			fmt.Println(i, s[i])
			return i
		}
	}
	return -1

}

//https://www.jianshu.com/p/990863e51429
/**
class Solution {
public:
  int firstUniqChar(string s)
  {
    int n=s.length();
	if (n ==0){
		return -1;
	}
	vector<int> dp(26,0);

    for(int i=0;i<n;i++)
	{
        dp[s[i]-'a']++;
	}

	for(int i=0;i<n;i++)
	{
       if(1 ==dp[s[i]-'a'])
	  {
         return i; //find
	  }
	}

	return -1; //not find


    }
};
**/
func main1() {
	//fmt.Println(firstUniqChar("leetcode"))
	//fmt.Println(firstUniqChar("cc"))       //数字相同
	//fmt.Println(firstUniqChar("z"))        //只有一个字母
	//fmt.Println(firstUniqChar("aadadaad")) //数字相同
	fmt.Println(1024/32, 1024>>5, 1<<31)

}
