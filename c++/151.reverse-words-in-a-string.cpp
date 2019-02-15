class Solution {
public:
   /**
   1 read
   
     自己反转字符串有什么难度
	 a 单词是通过空格来区分的，
	 b 多个空格怎么办 反转后必须用第一个空格分割，单词长度会发生变化。
	 c 因为每个单词长度不一样，反转后前面或者后面包含多余的空格不能包括 ___xxx___
     d 翻转的单词，而不是字符串 
	
	 直接想不出来 最基本的也想不出来
	
	主要是空格的问题：前导空格，后置空格，以及中间多余的空格。不能够用额外的空间，所以我们只能在原字符串上做修改，而不能另申请 
    解题思路：先翻转单词，再整体翻转，最后遍历的过程中，将多余的空格删除
	
   2.step
   
   methd1 time o(n) space o(n)
    1 遍历字符串 遇到获取单词
	2 遇到空格 存储单词到vector中
	3. 输出vecotr单词。用空格拼接，最后一个不拼接
	//执行用时: 12 ms, 在Reverse Words in a String的C++提交中击败了22.96% 的用户
    
  methd2 time o(n2) space(1)
  1.单词反转
  2 去空格
  3 在字符串的翻转
  /执行用时: 16 ms, 在Reverse Words in a String的C++提交中击败了16.02% 的用户
   3.test
   https://blog.csdn.net/u010412719/article/details/50875622
   meth3
   执行用时: 8 ms, 在Reverse Words in a String的C++提交中击败了47.35% 的用户
   **/
   //https://segmentfault.com/q/1010000004530895/a-1020000004542115
   //https://blog.csdn.net/lixq05/article/details/81158009
    void reverseWords(string &s) {
        
    }
};



/**
//进阶: 请选用C语言的用户尝试使用 O(1) 空间复杂度的原地解法
void reverseWords(char *s) 
{
    
}
**/

// CPP program to reverse a string 
#include <stdio.h> 
  
/* function prototype for utility function to 
  reverse a string from begin to end  */
void reverse(char* begin, char* end); 
  
/*Function to reverse words*/
void reverseWords(char* s) 
{ 
    char* word_begin = s; 
    char* temp = s; /* temp is for word boundry */
  
    /*STEP 1 of the above algorithm */
    while (*temp) { 
        temp++; 
        if (*temp == '\0') { 
            reverse(word_begin, temp - 1); 
        } 
        else if (*temp == ' ') { 
            reverse(word_begin, temp - 1); 
            word_begin = temp + 1; 
        } 
    } /* End of while */
  
    /*STEP 2 of the above algorithm */
    reverse(s, temp - 1); 
} 
  
/* UTILITY FUNCTIONS */
/*Function to reverse any sequence starting with pointer 
  begin and ending with pointer end  */
void reverse(char* begin, char* end) 
{ 
    char temp; 
    while (begin < end) { 
        temp = *begin; 
        *begin++ = *end; 
        *end-- = temp; 
    } 
} 
 

/* Driver function to test above functions */
int main() 
{ 
    char s[] = "i like this program very much"; 
    char* temp = s; 
    reverseWords(s); 
    printf("%s", s); 
    getchar(); 
    return 0; 
} 