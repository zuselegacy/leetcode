class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        vector<int> nums2 = nums;
        sort(nums2.begin(),nums2.end());
        int curr=0, start=0;
        for(int i=0;i<nums.size();i++){
            vector<int>::iterator it = std::lower_bound(nums2.begin(),nums2.end(),nums[i]);
            result.push_back(it-nums2.begin());            
        }
        return result;        
    }
};
