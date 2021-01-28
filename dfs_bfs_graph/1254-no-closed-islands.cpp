class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int x, int y) {
        bool result = true;       
        if(x==0 || x==grid.size()-1 || y==0 || y == grid[0].size()-1)
            result = false;
        grid[x][y] = 1;
        if(x-1 >=0 && grid[x-1][y] == 0)
            result = result & dfs(grid, x-1, y);
        if(x+1 <grid.size() && grid[x+1][y] == 0)
            result = result & dfs(grid, x+1,y);
        if(y-1 >=0 && grid[x][y-1]==0)
            result = result & dfs(grid,x,y-1);
        if(y+1 <grid[0].size() && grid[x][y+1] == 0)
            result = result & dfs(grid,x,y+1);
        return result;
        
    } 
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 0)
                    count = count +dfs(grid, i, j);
            }
        }
        return count;
    }
};
