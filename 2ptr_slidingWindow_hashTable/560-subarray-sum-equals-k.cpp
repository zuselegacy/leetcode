class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int prefixSum=0;
        map<int,int> hashMap;
        hashMap[0]=1;
        for(int i=0;i<nums.size();i++) {
            prefixSum += nums[i];
            if(hashMap.find(prefixSum-k)!=hashMap.end()) {
                count += hashMap[prefixSum-k];
            }
            hashMap[prefixSum]++;            
        }
        return count;
        
    }
};
