class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicatePtr=0;
        for(int i=0;i<nums.size();i++) {            
            if(i==0 ||i==1|| nums[i] > nums[duplicatePtr-2]) {                
                swap(nums[duplicatePtr],nums[i]);
                duplicatePtr++;
            }             
        }
        return duplicatePtr;
        
    }
};
