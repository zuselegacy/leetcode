class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalBeams = 0;
        int activeDevices =0; 
        for(int i=0;i<bank.size();i++) {
            int curDevices = 0;
            for(int j=0;j<bank[i].size();j++) {
                if(bank[i][j] == '1') {
                    curDevices++;
                    totalBeams += activeDevices;
                }                
            }
            if(curDevices > 0 )
                activeDevices = curDevices;
        }
        return totalBeams;
        
    }
};
