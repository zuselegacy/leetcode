// shrinking window pattern can be used as array is sorted
// another method that can be used because of sorted array is bin search
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left =0, right = numbers.size()-1;
        vector<int> result;
        while(left<right) {
            if(numbers[left] + numbers[right] == target) {
                result.push_back(left+1);
                result.push_back(right+1);
                return result;
            } else if(numbers[left]+numbers[right] >target) {
                right--;
            } else {
                left++;
            }
        }
        return result;
        
    }
};
