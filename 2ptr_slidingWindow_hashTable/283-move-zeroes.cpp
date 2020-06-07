// 2ptr - i represents ptr uptil which array is transformed correctly
// problem - initial value of zeroPtr, is set only when zero is found
class Solution {
public:
    void swap(int& x,int& y) {
        int tmp =x;
        x = y;
        y=tmp;
    }
    void moveZeroes(vector<int>& nums) {
       int zeroPtr =-1;
       for(int i=0;i<nums.size();i++) {
           if(zeroPtr!=-1 && nums[i] != 0) {
             swap(nums[i],nums[zeroPtr]);
             zeroPtr++;
           } else if(nums[i] ==0 && zeroPtr==-1) {
               zeroPtr = i;
           }
       }
        
    }
};
