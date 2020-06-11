#include <algorithm>
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> lastPos(26,0);
        int prevLastPos=-1,currLastPos=0;
        vector<int> result;
        for(int i=0;i<S.size();i++){
            lastPos[S[i]-'a'] = i;     
        }
        for(int i=0;i<S.size();i++){
            currLastPos = std::max(currLastPos,lastPos[S[i]-'a']);
            if(currLastPos == i) {
                result.push_back(currLastPos-prevLastPos);
                prevLastPos = currLastPos;
                currLastPos = -1;
            }
        }
        return result;        
    }
};
