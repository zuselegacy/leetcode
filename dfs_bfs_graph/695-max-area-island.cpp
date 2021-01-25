class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int* area) {
        grid[i][j] = 0;
        (*area)++;
        if(i-1 >= 0 && grid[i-1][j] == 1) 
            dfs(grid, i-1, j, area);
        if(i+1 <grid.size() && grid[i+1][j] == 1)
            dfs(grid, i+1, j, area);
        if(j-1 >=0 && grid[i][j-1] == 1)
            dfs(grid, i, j-1, area);
        if(j+1 <grid[0].size() && grid[i][j+1] ==1 )
            dfs(grid, i, j+1, area);        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0; i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, i, j, &area);
                    if(area > maxArea)
                        maxArea = area;
                }                
            }
        }
        return maxArea;
    }    
};
