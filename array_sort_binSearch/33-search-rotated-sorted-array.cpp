class Solution {
public:
    int findStartIndex(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] >= nums[0]) 
                low = mid + 1;
            else
                high = mid -1;
        }
        return low;
    }
    int binSearch(vector<int>& nums, int low, int high, int target) {
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
                return mid;
            else if(target < nums[mid])
                high = mid -1;
            else
                low = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int startIndex = findStartIndex(nums);
        // no rotation
        if(startIndex == nums.size()) {            
            return binSearch(nums, 0, nums.size()-1, target);
        } else {
            if(target >= nums[0])
                return binSearch(nums, 0,startIndex -1,target);
            else
                return binSearch(nums, startIndex, nums.size()-1,target);
            
        }
        return -1;
    }
};
