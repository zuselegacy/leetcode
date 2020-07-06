class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        vector<int>::iterator start = std::lower_bound(nums.begin(),nums.end(),target);
        if(start == nums.end()) {
            return false;
        }
        vector<int>::iterator end = std::upper_bound(nums.begin(),nums.end(),target);
        if(end-start >nums.size()/2)
            return true;
        else
            return false;                
    }
};
