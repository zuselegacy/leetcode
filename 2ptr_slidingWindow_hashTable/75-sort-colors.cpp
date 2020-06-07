class Solution {
public:
    void sortColors(vector<int>& nums) {
        int onePtr =0, twoPtr = nums.size()-1;
        int i=0;
        while(i<=twoPtr) {
            if(nums[i]==0){
                swap(nums[i],nums[onePtr]);
                onePtr++;
                i++;
            } else if(nums[i]==1){
                i++;
            } else {
                swap(nums[i],nums[twoPtr]);
                twoPtr--;
            }
        }
        
    }
};
