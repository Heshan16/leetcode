/*
 Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return;
        int rows=board.size(),cols=board[0].size();
        for(int j=0;j<cols;j++)
            if(board[0][j]=='O')
                replace_path(board,0,j,rows,cols);
        for(int j=1;j<rows;j++) {
            if(board[j][0]=='O')
                replace_path(board,j,0,rows,cols);
            if(board[j][cols-1]=='O')
                replace_path(board,j,cols-1,rows,cols);
        }
        for(int j=0;j<cols;j++)
            if(board[rows-1][j]=='O')
                replace_path(board,rows-1,j,rows,cols);
    
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++) {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='T')
                    board[i][j]='O';
            }
    }
        
    void replace_path(vector<vector<char>>& board,int i,int j,int rows,int cols) {
        board[i][j]='T';
        if(i-1>0 && board[i-1][j]=='O')
            replace_path(board,i-1,j,rows,cols);
        if(i+1<rows-1 && board[i+1][j]=='O')
            replace_path(board,i+1,j,rows,cols);
        if(j-1>=1 && board[i][j-1]=='O')
            replace_path(board,i,j-1,rows,cols);
        if(j+1<cols-1 && board[i][j+1]=='O')
            replace_path(board,i,j+1,rows,cols);
    }
};
