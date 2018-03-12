/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). 
*/

//Solution 1 dp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz=triangle.size();
        vector<int> cursum(sz);
        cursum[0]=triangle[0][0];
        for(int i=1;i<sz;i++) {
            cursum[i]=cursum[i-1]+triangle[i][i];
            for(int j=i-1;j>0;j--)
                cursum[j]=triangle[i][j]+min(cursum[j],cursum[j-1]);
            cursum[0]+=triangle[i][0];
        }
        int min=INT_MAX;
        for(int i=0;i<sz;i++)
            if(cursum[i]<min)
                min=cursum[i];
        return min;
    }
};


//solution 2,more concise dp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> res(triangle[triangle.size()-1]);
        for(int i=triangle.size()-2;i>=0;i--)
            for(int j=0;j<=i;j++)
                res[j]=triangle[i][j]+min(res[j],res[j+1]);
        return res[0];
    }
};

//Solution 3,with no space cost dp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-2;i>=0;i--)
            for(int j=0;j<=i;j++)
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
        return triangle[0][0];
    }
};

