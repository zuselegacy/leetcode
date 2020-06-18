// no need to check for duplicates since count of index tuples
// reduce 3 sum less than to 2sum less than problem by fixing the first element
// 2 sum less than - to find count: r-l
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) {
            int sum = target - nums[i];
            // find 2sum pairs < sum
            int left = i+1;
            int right = nums.size()-1;
            while(left < right) {
                if(nums[left] + nums[right] < sum) {
                    count = count + (right - left);
                    left++;
                } else {
                    right--;
                }
            }
        }
        return count;
        
    }
};
