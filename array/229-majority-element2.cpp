// see  https://leetcode.com/problems/majority-element-ii/discuss/63537/My-understanding-of-Boyer-Moore-Majority-Vote
class Solution {
public:
    int count(vector<int>& nums, int num){
        int count =0;
        for(int i=0;i<nums.size();i++) {
            if(num == nums[i])
                count++;
        }
        return count;
    }
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int counter1 = 0,counter2 = 0;
        int element1, element2;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == element1)
                counter1++;
            else if(nums[i] == element2)
                counter2++;
            else if(counter1==0) {
                counter1++;
                element1 = nums[i];
            } else if(counter2==0) {
                counter2++;
                element2 = nums[i];
            } else {
                counter1--;
                counter2--;
            }                
        }
        if(count(nums,element1) > nums.size()/3)
          result.push_back(element1);
        if(count(nums,element2) > nums.size()/3)
          result.push_back(element2);
        return result;
    }
};
