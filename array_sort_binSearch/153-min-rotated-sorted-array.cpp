class Solution {
public:   
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] >= nums[0]) 
                low = mid + 1;
            else
                high = mid -1;
        }
        return low == nums.size()? nums[0]:nums[low];                   
    }
};
