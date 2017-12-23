/*
 Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty())
            return true;
        int rows=board.size(),cols=board[0].size();
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if((board[i][j]==word[0]) && recur_find(board,i,j,word,0))
                   return true;
            }
        }
        return false;
    }
    bool recur_find(vector<vector<char>> &board,int i,int j,string &s,int index) {
        if(index+1==s.size())
            return true;
        char c=s[index];
        board[i][j]=0;
        if( (i+1<board.size() && board[i+1][j]==s[index+1] && recur_find(board,i+1,j,s,index+1)) 
           || (j+1<board[i].size() && board[i][j+1]==s[index+1] && recur_find(board,i,j+1,s,index+1)) 
           || (i-1>=0 && board[i-1][j]==s[index+1] && recur_find(board,i-1,j,s,index+1))
           || (j-1>=0 && board[i][j-1]==s[index+1] && recur_find(board,i,j-1,s,index+1)) )
            return true;
        board[i][j]=c;
        return false;
    }
};
