// gotcha - handle -ve modulo remainders
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        map<int,int> remMap;
        remMap[0]=1;
        int count =0;
        int prefixSum=0;
        for(int a:A) {            
            prefixSum = (prefixSum + a)%K;
            if(prefixSum<0)
                prefixSum=prefixSum + K;                        
            count = count + remMap[prefixSum]++;
        }
        return count;
        
    }
};
