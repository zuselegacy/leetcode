class Solution {
public:
    void dfs(int city,vector<vector<int>>& graph, vector<bool>& visit) {
        visit[city] = true;
        for(int i =0;i<graph[0].size();i++) {
            if(graph[city][i] ==1 && !visit[i])
                dfs(i,graph,visit);                
        }                
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visit(isConnected.size(), false);
        int count = 0;
        for(int i=0; i<isConnected.size();i++) {            
            if(!visit[i]) {
                dfs(i,isConnected, visit);
                count++;
            }
        }
        return count;                
    }    
};

