class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> numMap;
        int prefixSum = 0;
        vector<int> result;
        for(int i=0;i<nums.size();i++) {            
            if(numMap.find(target-nums[i])!=numMap.end()) {
                result.push_back(numMap[target-nums[i]]);
                result.push_back(i);
                return result;
            } else {
                numMap[nums[i]] = i;
            }
            
        }
        return result;            

    }
};
