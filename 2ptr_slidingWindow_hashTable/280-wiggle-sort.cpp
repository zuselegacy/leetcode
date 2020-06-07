class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i=1;i<nums.size();i++) {
            bool shouldSwap = false;
            if(i%2==1) {
                shouldSwap = ! (nums[i-1] <=nums[i]);                
            } else {
                shouldSwap = !(nums[i-1] >=nums[i]);
            }
            if(shouldSwap) {
                swap(nums[i],nums[i-1]);
            }                
        }
        
    }
};
