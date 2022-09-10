class Comp {
    public:
    bool operator()(const vector<int>& i1, const vector<int>& i2) const {
        if(i1[0]!=i2[0])
            return i1[0] < i2[0];
        else 
            return i1[1] < i2[1];
    }
    
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),Comp());
        vector<vector<int>> soln;
        vector<int> interval = intervals[0];
        
        for(int i=1;i<intervals.size();i++) {
            // overlap
            if(intervals[i][0] <= interval[1]) {
                interval[1] = max(interval[1],intervals[i][1]);                
            } else {
                soln.push_back(interval);
                interval = intervals[i];
            }          
        }
        soln.push_back(interval);
        return soln;        
    }
};
