class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> timeToReachCity (dist.size(),0);
        for(int i=0;i<dist.size();i++) {
            int upcast = dist[i]%speed[i]==0?0:1;
            timeToReachCity[i] = dist[i]/speed[i] + upcast;
        }
        sort(timeToReachCity.begin(),timeToReachCity.end());
        
        int monstersKilled = 0;
        int clock=0;
        for(int i=0;i<timeToReachCity.size();i++) {
            if(clock < timeToReachCity[i]) {
                monstersKilled++;
                clock++; // charging time
            } else
                break;
        }
        return monstersKilled;
    }
};
