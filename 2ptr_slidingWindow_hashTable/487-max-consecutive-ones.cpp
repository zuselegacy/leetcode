// 2ptr - sliding window variation
// template: since plbm is to max a valid subarry:
// while(right<array.size)
// check if currArray is valid
// when it becomes invalid, advance left till it becomes valid again
// evaluation value of array and compare to max
// right++
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int left = 0,right=0;
      int noOfZero=0;   
        int max1=0;
        while(right<nums.size()) {
            if(nums[right] ==0) {
                noOfZero++;
            }            
            while(noOfZero>1) {
                // invalid condition - advance left till we cross 0
                if(nums[left]==0)
                    noOfZero--;
                left++;                                
            } 
            max1=max(max1,right-left+1);                        
            right++;
        }
        return max1;
        
    }
};
