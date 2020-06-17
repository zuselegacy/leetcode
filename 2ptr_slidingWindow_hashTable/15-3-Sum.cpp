// sort and use shrinking pattern - fix an element and do 2Sum with remaining array
// skip duplicates for i, left and right
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int left = i+1, right= nums.size() -1;
            int sum = 0-nums[i];
            while(left < right) {
                if(nums[left]+nums[right]<sum || (left>i+1 && nums[left] == nums[left-1])) {
                    left++;
                }
                else if(nums[left]+nums[right]>sum || (right<nums.size()-1 && nums[right] == nums[right+1])) {
                    right--;
                } else {
                    vector<int> soln{nums[i],nums[left],nums[right]};
                    result.push_back(soln);                    
                    left++;
                    right--;
                }              
            }            
        }
        return result;                        
        
    }
};
