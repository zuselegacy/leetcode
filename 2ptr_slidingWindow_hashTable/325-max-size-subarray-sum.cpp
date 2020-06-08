class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum=0;
        int maxLen=0;
        map<int,int> sumMap;
        sumMap[0] = -1;
        for(int i=0;i<nums.size();i++) {
            sum = sum + nums[i];
            /*if(sum == k) {
                maxLen = max(maxLen,i+1);
            }*/ 
            if(sumMap.find(sum-k)!=sumMap.end()) {
                maxLen = max(maxLen,i-sumMap[sum-k]);
            }
            if(sumMap.find(sum)==sumMap.end()){
                sumMap[sum] = i;
            }            
        }
        return maxLen;
        
    }
};
