class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        queue<int> q;
        vector<int> indegree(numCourses, 0);                
        for(int i=0;i<prerequisites.size();i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        for(int i=0;i<numCourses;i++) {
            if(indegree[i] == 0) {
                q.push(i);
                order.push_back(i);
            }
        }
        while(!q.empty()) {
            int c = q.front();
            q.pop();
            for(int i=0;i<graph[c].size();i++) {                
                indegree[graph[c][i]]--;
                if(indegree[graph[c][i]] == 0) {
                    q.push(graph[c][i]);
                    order.push_back(graph[c][i]);                    
                }
            }
        }        
        if(order.size() < numCourses)
            order.clear();
        return order;
    }
    map<int,vector<int>> graph;
};
