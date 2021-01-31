class Solution {
public:
    bool dfs(int course, vector<int>& visit) {
        visit[course] = 1;        
        for(int i=0;i<graph[course].size();i++) {
            if(visit[graph[course][i]] == 1)
                return false;
            else if(visit[graph[course][i]] == 0) {
                if(dfs(graph[course][i], visit) == false)
                    return false;                
            }
        }
        visit[course] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visit(numCourses, 0);
        for(int i=0;i<prerequisites.size();i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++) {            
            if(visit[i] == 0 && dfs(i,visit) == false)
                return false;
        }
        return true;                
    }
    map<int,vector<int>> graph;
};
