class Solution {
public:
    bool splitArray(vector<int>& nums) {        
        if(nums.size()<7)
            return false;
        
        map<int,vector<int>> sumMap;        
        map<int,int> prefixMap;        
        int prefixSum=0;
        for(int i=0;i<nums.size();i++) {
            prefixSum += nums[i];
            prefixMap[i] = prefixSum;
            sumMap[prefixSum].push_back(i);            
        }
        
        for(int i=1;i<=nums.size()-6;i++) {
            int sum = prefixMap[i-1];
            int searchSum= sum*2 +nums[i];
            auto it = sumMap.find(searchSum);
            if(it == sumMap.end()) {
                continue;
            } 
            for(int j: sumMap[searchSum]) {
                j = j +1;
                if(j>= i+1 && j<= nums.size()-4) {
                    int searchSum = sum*3 + nums[i] + nums[j];
                    auto it2 = sumMap.find(searchSum);
                    if(it2!=sumMap.end()) {
                        for(int k: sumMap[searchSum]) {
                            k = k+1;
                            if(k>=j+1 && k<=nums.size()-2) {
                                if(prefixMap[nums.size()-1] == sum*4 + nums[i]+nums[j]+nums[k]) {
                                    return true;
                                }
                                
                            }
                        }
                        
                    }
                }
            }
        }
        return false;                        
    }
};
