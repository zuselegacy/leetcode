// 2ptr sliding window used here since its positive integers and find >=sum not exact sum
// 2ptr sliding window with min pattern
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum=0;
        int left=0,right=0;
        int minLen = INT_MAX;
                
        while(right<nums.size()) {
            sum = sum + nums[right];
            if(sum >=s) {
                //minLen = min(minLen,right-left+1);
                while(sum>=s) {
                    sum = sum - nums[left];
                    left++;                    
                }
                minLen = min(minLen,right-left+2);                
            }
            right++;            
        }
        return minLen==INT_MAX?0:minLen;                  
    }
};
