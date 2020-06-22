class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> stateMap;  // count of every char to be filled
        int count = 0;  // total count of chars already filled
        int left = 0, right = 0;
        int winSize = INT_MAX;
        int winStart=0;
        int winEnd=0;
        
        if(t.empty()) {
            return "";
        }
        
        for(int i=0;i<t.size();i++) {
            stateMap[t[i]]++;
        }
        
        while(right<s.size()) {
            if(stateMap.find(s[right]) != stateMap.end()) {
                if(stateMap[s[right]]>0)
                    count++;
                stateMap[s[right]]--;
            }
            while(count== t.size()) {
                if((right-left+1) < winSize) {
                    winSize = right-left+1;
                    winStart = left;
                    winEnd = right;
                }
                if(stateMap.find(s[left])!=stateMap.end()) {
                    stateMap[s[left]]++;
                    if(stateMap[s[left]]>0)
                        count--;                    
                }
                left++;                
            }
            right++;            
        }
        
        return (winSize == INT_MAX? "" : s.substr(winStart,winSize));               
    }
};
