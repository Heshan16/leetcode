/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/


class Solution {
public:
    int totalNQueens(int n) {
        if(n<1)
            return 0;
        vector<string> cur(n,string(n,'.'));
        vector<bool> line(5*n,false);
        return recur_solve(cur,0,n,line);
    }
    int recur_solve(vector<string> &cur,int i,int n,
                     vector<bool> &line) {
        if(i>=n)
            return 1;
        int res=0;
        for(int j=0;j<n;j++) {
            if(!line[j] && !line[i+j+n] && !line[i-j+9+3*n]) {
                line[j]=line[i+j+n]=line[i-j+9+3*n]=true;
                cur[i][j]='Q';
                res+=recur_solve(cur,i+1,n,line);
                line[j]=line[i+j+n]=line[i-j+9+3*n]=false;
                cur[i][j]='.';
            }
        }
        return res;
    }
};
