class Solution {
public:    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int,priority_queue<int,vector<int>,greater<int>>> q;
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++) {
                int index = i-j + mat[0].size()-1;
                q[index].push(mat[i][j]);                
            }
        }
        
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++) {
                int index = i-j+mat[0].size()-1;
                mat[i][j] = q[index].top();
                q[index].pop();
            }
        }
        return mat;
        
    }
};
