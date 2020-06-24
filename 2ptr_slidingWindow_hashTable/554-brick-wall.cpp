class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int> prefixCount;
        int maxBoundaryCross = INT_MIN;
        
        for(int i=0;i<wall.size();i++) {
            int prefixSum=0;
            for(int j=0;j<wall[i].size()-1;j++){
                prefixSum += wall[i][j];
                prefixCount[prefixSum]++;
                if(prefixCount[prefixSum] > maxBoundaryCross) {
                    maxBoundaryCross = prefixCount[prefixSum];
                }
            }
        }
        return (maxBoundaryCross == INT_MIN?wall.size(): wall.size() - maxBoundaryCross);
    }
};
