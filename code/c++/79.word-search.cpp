#include <iostream>
#include <string>
#include <vector>
using namespace std; 
/**
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
 **/
class Solution {
private:
      int m_rows;
      int m_cols;
      int m_lenth;
      string* ptr;
public:
    bool exist(vector<vector<char> >& board, string word) {
   
     int m_rows = board.size();
     if (m_rows == 0)  return false;
     int m_cols =board[0].size();
     m_lenth =word.length();
     ptr = &word;

     for (int i=0;i < m_rows;i++)
     {
         for (int j=0;j < m_cols;j++)
         {   //word[0]
             if (dfs(board,i,j,0))
             {
                 return true;
             }
         }
     }

     return false;    
    }

    bool dfs(vector<vector<char> >& board,int i,int j,int index)
    {
        if (i>= m_rows || j>=m_cols || i< 0 ||  j<0 || index>=m_lenth || board[i][j] != ptr->at(index))
        {
            return false;//end
        }
        if (index == m_lenth-1)
        {
            return true; //end
        }
        
        char visited  = board[i][j];
        board[i][j]='\0';  //防止死循环 A-->B B-->A
        bool left = dfs(board,i,j-1,index+1);
        bool right = dfs(board,i,j+1,index+1);
        bool up   = dfs(board,i-1,j,index+1);
        bool down = dfs(board,i+1,j,index+1);
        board[i][j] =visited;

       if ( left || right || up || down)
       {
           return true;
       }
       return false;
    }
};
//g++ -g -Wall -std=c++11
int main()
{
    vector<char> v1 = { 'A','B','C','E' };
    vector<char> v2 = { 'S','F','C','S'};
    vector<char> v3 = { 'A','D','E','E'};

    vector<vector<char>> board;
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);
    string word("ABCCED");
    Solution solution;
    cout<< solution.exist(board,word);

}