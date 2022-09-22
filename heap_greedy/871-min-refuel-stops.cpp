class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int lastStop=0;
        int refuel=0;
        
        vector<int> last;
        last.push_back(target);
        last.push_back(0);
        stations.push_back(last);
            
        for(int i=0;i<stations.size();i++) {
            int pos = stations[i][0];
            int fuel = stations[i][1];
            startFuel = startFuel- (pos-lastStop) ;
            lastStop = pos;
            while(!pq.empty() && startFuel<0) {
                startFuel += pq.top();                
                pq.pop();
                refuel++;
            }
            if(pq.empty() && startFuel<0)
                return -1;
            pq.push(fuel);
        }
        return refuel;            
        
    }
};
