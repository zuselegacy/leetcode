// use multiset for storing multiple times the same element
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;        
        multiset<int> nums1Set(nums1.begin(),nums1.end());

        for(int j=0;j<nums2.size();j++) {
            if(nums1Set.find(nums2[j])!= nums1Set.end()) {
                    result.push_back(nums2[j]);
                    nums1Set.erase(nums1Set.find(nums2[j]));
            }
        }
        return result;
    }
};
