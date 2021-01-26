class Solution {
public:
    void dfs(char c, map<char,vector<char>>& graph, set<char>& visited, char* minChar) {
        if(c -'a' < *minChar - 'a')
            *minChar = c; 
        visited.insert(c);
        
        for(int i=0; i< graph[c].size(); i++) {
            if(visited.find(graph[c][i]) == visited.end())
               dfs(graph[c][i],graph,visited,minChar);
        }        
    }
    string smallestEquivalentString(string A, string B, string S) {
        map<char,vector<char>> graph;
        for(int i=0;i<A.size();i++) {
            graph[A[i]].push_back(B[i]);
            graph[B[i]].push_back(A[i]);                        
        }
        string output;
        for(int i=0;i<S.size();i++) {
            set<char> visited;
            char minChar = '{';
            dfs(S[i], graph, visited, &minChar);
            output.push_back(minChar);
        }
        return output;
        
    }
};
