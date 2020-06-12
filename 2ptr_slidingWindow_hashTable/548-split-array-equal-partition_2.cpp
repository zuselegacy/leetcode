// break n^3 into n^2 by fixing j first
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if(nums.size()<7)
            return false;

        map<int,int> prefixMap;
        int prefixSum=0;
        for(int i=0;i<nums.size();i++) {
            prefixSum += nums[i];
            prefixMap[i] = prefixSum;
        }

        for(int j=3;j<nums.size()-3;j++) {
            set<int> sums;
            for(int i=1;i<j-1;i++) {
                if(prefixMap[i-1] == prefixMap[j-1]-prefixMap[i]) {
                    sums.insert(prefixMap[i-1]);
                }                
            }
            for(int k=j+2;k<nums.size()-1;k++) {
                int sum1 = prefixMap[k-1]-prefixMap[j] ;
                int sum2 = prefixMap[nums.size()-1] - prefixMap[k];
                if(sum1 == sum2 && sums.find(sum1)!=sums.end()) {
                    return true;
                }
            }
                   
            
        }
        return false;
    }
};
