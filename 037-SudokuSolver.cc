/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution. 
*/


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> rowbit(9,0);
        vector<int> colbit(9,0);
        vector<int> gridbit(9,0);
        vector<pair<int,int>> vm;
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++) {
                if(board[i][j]!='.') {
                    int t=1<<(board[i][j]-'0');
                    rowbit[i]|=t;
                    colbit[j]|=t;
                    gridbit[(i/3)*3+j/3]|=t;
                }
                else {
                    vm.push_back(make_pair(i,j));
                }
            }
        
        dfs(board,vm,rowbit,colbit,gridbit,0);
    }
    bool dfs(vector<vector<char>> &board,vector<pair<int,int>> &vm,vector<int> &row,vector<int> &col,vector<int> &grid,int index) {
        if(index>=vm.size())
            return true;
        auto p=vm[index];
        int i=p.first,j=p.second;
        int bit=row[i]|col[j]|grid[(i/3)*3+j/3];
        for(int k=1;k<=9;k++) {
            int t=1<<k;
            if(!(t&bit)) {
                row[i]|=t;
                col[j]|=t;
                grid[(i/3)*3+j/3]|=t;
                
                board[i][j]='0'+k;
                if(dfs(board,vm,row,col,grid,index+1))
                    return true;
                t=~t;
                row[i]&=t;
                col[j]&=t;
                grid[(i/3)*3+j/3]&=t;
               // board[i][j]='.';
            }
        }
        return false;
    }
};
