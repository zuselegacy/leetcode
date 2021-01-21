class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
        image[sr][sc] = newColor;
        if(sr -1 >= 0 && image[sr-1][sc] == oldColor)
            dfs(image, sr-1, sc, newColor, oldColor);
        if(sr+1 <image.size() && image[sr+1][sc] == oldColor)
            dfs(image, sr + 1, sc, newColor, oldColor);
        if(sc-1 >=0 && image[sr][sc-1] == oldColor)
            dfs(image, sr, sc-1, newColor, oldColor);
        if(sc+1 < image[0].size() && image[sr][sc+1] == oldColor)
            dfs(image, sr, sc+1, newColor, oldColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor == newColor)
            return image;
        dfs(image, sr, sc, newColor, oldColor);
        return image;        
    }
};
