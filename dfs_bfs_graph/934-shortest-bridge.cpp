class Solution {
public:
    void dfs(vector<vector<int>>& A,queue<pair<int,int>>& q, int x, int y) {
        A[x][y] = 2;
        q.push(make_pair(x,y));
        if(x-1 >=0 && A[x-1][y] == 1)
            dfs(A, q, x-1,y);
        if(x+1 <A.size() && A[x+1][y] == 1)
            dfs(A, q, x+1,y);
        if(y-1 >=0 && A[x][y-1] ==1)
            dfs(A, q, x,y-1);
        if(y+1 < A[0].size() && A[x][y+1] ==1)
            dfs(A, q, x,y+1);        
    }
    int shortestBridge(vector<vector<int>>& A) {
        int x,y;
        queue<pair<int,int>> q;
        for(int i=0;i<A.size();i++) {
            for(int j=0;j<A[0].size();j++) {
                if(A[i][j] == 1) {
                    x = i;
                    y = j;
                    break;
                }                                        
            }
        }
        dfs(A,q, x, y);
        int count = -1;
        while(!q.empty()) {
            int size = q.size();
            count++;
            for(int i=0;i<size;i++) {
                pair<int,int> node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                A[x][y]=2;
                if(x-1>=0 && A[x-1][y] == 0)
                    q.push(make_pair(x-1,y));
                else if(x-1>=0 && A[x-1][y] == 1)
                    return count;
                if(x+1<A.size() && A[x+1][y] == 0)
                    q.push(make_pair(x+1,y));
                else if(x+1<A.size() && A[x+1][y] == 1)
                    return count;
                if(y-1>=0 && A[x][y-1] == 0)
                    q.push(make_pair(x,y-1));
                else if(y-1>=0 && A[x][y-1] == 1)
                    return count;
                if(y+1<A[0].size() && A[x][y+1] == 0)
                    q.push(make_pair(x,y+1));
                else if(y+1<A[0].size() && A[x][y+1] == 1)
                    return count;                
            }
        }
        return count;
        
    }
};
