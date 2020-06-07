// 2 ptr style approach to find intersection, does sort as array is unsorted
// pattern bounds check and increment pointer based on condition
// pattern use of min - no seperate increment of pointers avoid increment both, increment only i or increment only j
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        for(int i=0,j=0;i<nums1.size()&& j<nums2.size();){
            int minInt = min(nums1[i],nums2[j]);
            if(nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
            }
            while(i<nums1.size() && nums1[i] == minInt)
                i++;
            while(j<nums2.size() && nums2[j] == minInt)
                j++;         
        }
        return result;
    }
};
