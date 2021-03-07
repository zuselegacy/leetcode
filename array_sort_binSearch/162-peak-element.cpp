class Solution {
public:
    int findPeakElement(vector<int>& nums) {
	// closed interval
	// last element is not evaluated
	// this is ok as if last element is the peak, it will terminate at the last element anyway
        int low = 0, high = nums.size()-1;        
        while(low < high) {
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[mid+1])
                high = mid;
            else
                low = mid + 1;
        }
        return low;        
    }
};
