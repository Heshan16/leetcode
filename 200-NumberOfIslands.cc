class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int count=0,rsz=grid.size(),csz=grid[0].size();
        for(int i=0;i<rsz;i++){
            for(int j=0;j<csz;j++) {
                if(grid[i][j]=='1'){
                    recur_find_island(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void recur_find_island(vector<vector<char>>& grid,int i,int j) {
        grid[i][j]='*';
        if(i+1<grid.size() && grid[i+1][j]=='1')
            recur_find_island(grid,i+1,j);
        if(i-1>=0 && grid[i-1][j]=='1')
            recur_find_island(grid,i-1,j);
        if(j+1<grid[0].size() && grid[i][j+1]=='1')
            recur_find_island(grid,i,j+1);
        if(j-1>=0 && grid[i][j-1]=='1')
            recur_find_island(grid,i,j-1);
    }
};
