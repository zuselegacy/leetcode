class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int majorityElement = nums[0];
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==majorityElement) {
                count++;
            } else {
                if(count == 0) {
                    count = 1;
                    majorityElement = nums[i];
                } else {
                    count--;
                }
            }
        }
        return majorityElement;
        
    }
};
