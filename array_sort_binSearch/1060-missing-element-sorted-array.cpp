class Solution {
public:
    // finds total missing elements in nums[start,index]
    int missingElementsCount(vector<int>& nums, int index) {
        int count =  (nums[index] - nums[0] +1) - (index +1);        
        return count;
    }
    int missingElement(vector<int>& nums, int k) {
        int low = 0, high = nums.size();
        while(low < high) {
            int mid = low + (high - low)/2;
            if(missingElementsCount(nums,mid) < k)
                low = mid + 1;                             
            else
                high = mid; 
        }
        int extra = k - missingElementsCount(nums,low-1);
        return nums[low - 1] + extra;    
    }
}; 
    
