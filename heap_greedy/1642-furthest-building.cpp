class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int prevH = heights[0];
        priority_queue<int,vector<int>,std::greater<int>> pq;
        int bricksUsed=0;
        
        for(int i=1;i<heights.size();i++) {
            if(heights[i]<=prevH) {
                prevH = heights[i];
                continue;
            }
            
            int height = heights[i] - prevH;            
            pq.push(height);
            if(pq.size() > ladders) {
                bricksUsed+= pq.top();
                pq.pop();
            }
            if(bricksUsed > bricks){
                return i-1;         
            }
            prevH = heights[i];
        }
        return heights.size()-1;
        
    }
};
