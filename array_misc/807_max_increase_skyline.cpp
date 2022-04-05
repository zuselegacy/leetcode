class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> maxRow(grid.size(),-1);
        vector<int> maxCol(grid.size(),-1);
        // find max in each row and each column
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid.size();j++) {
                if(grid[i][j] > maxRow[i])
                    maxRow[i] = grid[i][j];
                if(grid[i][j] > maxCol[j])
                    maxCol[j] = grid[i][j];
            }
        }
        
        int totalSum=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid.size();j++) {
                if(min(maxRow[i],maxCol[j]) > grid[i][j])
                    totalSum += (min(maxRow[i],maxCol[j]) -grid[i][j]);
            }
        }
        return totalSum;
    }
};
