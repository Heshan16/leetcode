/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int lasti=0,beg=0,end=n-1,firs=1,last=0;
        //注意考虑循环直接跳出的情况
        for(;n>1;n-=2) {
            last=firs+n*4-5,lasti=last;
            for(int i=beg;i<=end;i++)
                res[beg][i]=firs++;
            for(int i=beg+1;i<end;i++) {
                res[i][beg]=last--;
                res[i][end]=firs++;
            }
            for(int i=beg;i<=end;i++)
                res[end][i]=last--;
            beg++,end--;
            firs=lasti+1;
        }
        if(n==1)
            res[beg][beg]=firs++;
        return res;
    }
};
