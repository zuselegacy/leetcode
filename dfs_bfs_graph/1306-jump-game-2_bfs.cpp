class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        bool* visit = new bool [arr.size()];
        for(int i=0;i<arr.size();i++)
            visit[i] = false;
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int index = q.front();
            q.pop();
            if(arr[index] == 0)
                return true;
            visit[index] = true;
            
            if(index + arr[index] < arr.size() && !visit[index+arr[index]])
                q.push(index + arr[index]);
            if(index - arr[index] >=0 && !visit[index-arr[index]])
                q.push(index - arr[index]);            
        }
        return false;
        
        
    }
};
