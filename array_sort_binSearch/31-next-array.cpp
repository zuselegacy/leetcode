#include<iostream>
class Solution {    
public:
    void reverse(vector<int>&nums, int left, int right) {        
        while(left<right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int pos = -1;
        for(int i=nums.size()-1;i>0;i--) {
            if(nums[i]>nums[i-1]) {                
                pos = i-1;                
                for(int j=nums.size()-1;j>=i;j--) {
                    if(nums[j]>nums[i-1]) {
                        int tmp = nums[pos];
                        nums[pos] = nums[j];
                        nums[j]= tmp;     
                        break;                        
                    }
                }
                break;
                
            }
        }
        reverse(nums,pos+1,nums.size()-1);
        
    }
};
