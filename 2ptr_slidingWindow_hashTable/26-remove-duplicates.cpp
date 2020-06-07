// partition ptr pattern
// gotcha- the property here is to check is currentNo is > prev processed no
// sincearray is transformed, a[i]>a[i-1] check will be wrong
// use duplicatePtr-1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicatePtr=0;
        for(int i=0;i<nums.size();i++) {
            if(i==0 || nums[i] > nums[duplicatePtr-1]) {
                swap(nums[duplicatePtr],nums[i]);
                duplicatePtr++;
            }
        }
        return duplicatePtr;
    }
};
