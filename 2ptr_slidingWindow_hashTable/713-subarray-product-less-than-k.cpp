class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int left=0,right=0;
        int prod=1;
        while(right<nums.size()) {
            prod = prod *nums[right];
            while(prod >= k && left<=right) {
                prod = prod/nums[left];
                left++;                 
            }            
           if(left >right) {
                right=left;
            }else {
                count = count + (right-left+1);
                right++;   
            }
                       
        }
        return count;        
    }
};
