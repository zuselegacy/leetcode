// balance numbers to 0
// add 0 if odd
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        for(int num=1;num<=n/2;num++) {
            result.push_back(num);
            result.push_back(-num);            
        }
        if(n%2 !=0)
            result.push_back(0);
        return result;
        
    }
};
