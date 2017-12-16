/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty())
            return res;
        res.reserve(matrix[0].size()*matrix.size());
        recur_find(res,matrix,0,matrix.size()-1,0,matrix[0].size()-1);
        return res;
    }
    void recur_find(vector<int> &res,vector<vector<int>> &matrix,int rb,int re,int cb,int ce) {
        if(rb>re || cb>ce)
            return;
        if(rb==re) {
            for(int i=cb;i<=ce;i++)
                res.push_back(matrix[rb][i]);
            return;
        }
        if(cb==ce) {
            for(int i=rb;i<=re;i++)
                res.push_back(matrix[i][cb]);
            return;
        }
        for(int i=cb;i<=ce;i++) {
            res.push_back(matrix[rb][i]);
        }
        for(int i=rb+1;i<=re;i++)
            res.push_back(matrix[i][ce]);
        for(int i=ce-1;i>=cb;i--)
            res.push_back(matrix[re][i]);
        for(int i=re-1;i>=rb+1;i--)
            res.push_back(matrix[i][cb]);
        recur_find(res,matrix,rb+1,re-1,cb+1,ce-1);
    }
};
