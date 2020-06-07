class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int src =0, dst=0;
        while(src<nums.size()) {
            if(nums[src] != val) {
                nums[dst] = nums[src];
                dst++;
            }
            src++;
        }
        return dst;
    }
};
