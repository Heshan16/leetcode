/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        int rn=obstacleGrid.size(),cn=obstacleGrid[0].size();
        vector<int> path(rn+1,0);
        if(!(path[rn-1]=!obstacleGrid[rn-1][cn-1]))
            return 0;
        for(int i=cn-1;i>=0;i--)
            for(int j=rn-1;j>=0;j--)
                path[j]=obstacleGrid[j][i]?0:path[j]+path[j+1];
        return path[0];
    }
};
