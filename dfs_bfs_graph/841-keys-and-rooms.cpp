class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int room) {
        visitedRooms.insert(room);
        for(auto toVisit:rooms[room]) {
            if(visitedRooms.find(toVisit) == visitedRooms.end()) {
                dfs(rooms, toVisit);
            }            
        }                
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms, 0);
        return visitedRooms.size() == rooms.size();
        
    }
    set<int> visitedRooms;
};
