class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(int i=0;i<times.size();i++) {
            vector<int> weight;
            weight.push_back(times[i][1]);
            weight.push_back(times[i][2]);
            graph[times[i][0]].push_back(weight);
        }
        vector<bool> visit(n+1, false);
        vector<int> dist(n+1, INT_MAX);        
        dist[k] = 0;
        
        while(true) {
            // find min vertice
            int minDist = INT_MAX;
            int vertice = 0;
            for(int i=1;i<=n;i++) {
                if(!visit[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    vertice = i;
                }                           
            }
            if(vertice == 0)
                break;
            visit[vertice] = true;
            // update dist
            if(graph.find(vertice) == graph.end())
                continue;
            for(int i=0;i<graph[vertice].size();i++) {
                int dest = graph[vertice][i][0];
                int delay = graph[vertice][i][1];
                dist[dest] = min(dist[dest], dist[vertice] + delay);
            }                        
        }
        int delay = INT_MIN;
        for(int i=1;i<=n;i++) {
            if(dist[i] > delay)
                delay = dist[i];
        }
        if(delay == INT_MAX)
            return -1;
        else
            return delay;
    }
    map<int,vector<vector<int>>> graph;    
};
