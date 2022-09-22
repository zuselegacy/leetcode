class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int min=INT_MAX;
        int max=INT_MIN;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]<nums[i-1])
                min = nums[i] < min?nums[i]:min;            
        }
        for(int i=nums.size()-1;i>0;i--) {
            if(nums[i] < nums[i-1])
                max = nums[i-1] > max?nums[i-1]:max;
        }
        if(min == INT_MAX)
            return 0;
        
        int l,r;
        for(int i=0;i<nums.size();i++) {
            if(min<nums[i]) {
                l = i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--) {
            if(max>nums[i]) {
                r =i;
                break;
            }
        }
        
        return r-l+1;
        
    }
};
