#include <iostream>
using namespace std;

/**
https://leetcode.com/problems/longest-substring-without-repeating-characters/
Given a string, find the length of the longest substring without repeating characters.

 */
class Solution {
public:
    int lengthOfLongestSubstring(string s)
     {
         vector<int> hash_map(256,-1);

         int out=0;
         int start=0;

         for (int end=0;end<s.size();end++)
         {
           start=max(start,hash_map[s[end]]+1);
           hash_map[s[end]]=end;
           out=max(out,end-start+1);
         }
         return out;
    }
};


int   main(int   argc, char*   argv[])
{
    Solution test;
    cout<<"abcabcbb = "<<test.lengthOfLongestSubstring("abcabcbb")<<endl;
    cout<<"bbbbb = "<<test.lengthOfLongestSubstring("bbbbb")<<endl;

    
    return   0;
}
//Longest Substring with At Most Two Distinct Characters