/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:

[[1,3,1],
 [1,5,1],
 [4,2,1]]

Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.
*/


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int rn=grid.size(),cn=grid[0].size();
        vector<int> sum_path(cn+1,INT_MAX);
        sum_path[cn-1]=0;
        for(int i=rn-1;i>=0;i--)
            for(int j=cn-1;j>=0;j--)
                sum_path[j]=min(sum_path[j+1],sum_path[j])+grid[i][j];
        return sum_path[0];
    }
};
