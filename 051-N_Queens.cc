/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if(n<1)
            return res;
        vector<string> cur(n,string(n,'.'));
        vector<bool> line(5*n,false);
  /*      vector<bool> col(n,false);
        vector<bool> leftline(2*n,false);
        vector<bool> rightline(2*n,false);*/
        recur_solve(res,cur,0,n,line);
        return res;
    }
    void recur_solve(vector<vector<string>> &res,vector<string> &cur,int i,int n,
                     vector<bool> &line) {
        if(i>=n)
            res.push_back(cur);
        for(int j=0;j<n;j++) {
            if(!line[j] && !line[i+j+n] && !line[i-j+9+3*n]) {
                line[j]=line[i+j+n]=line[i-j+9+3*n]=true;
                cur[i][j]='Q';
                recur_solve(res,cur,i+1,n,line);
                line[j]=line[i+j+n]=line[i-j+9+3*n]=false;
                cur[i][j]='.';
            }
        }
    }
};
