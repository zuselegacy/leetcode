class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majorityElement;
        for(int i=0;i<nums.size();i++) {
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
