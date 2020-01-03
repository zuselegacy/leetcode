class Solution {
public:
    vector<vector<int>> soln;
    void generate(vector<int>& nums, int pos) {
        if(pos==nums.size()) {
            soln.push_back(nums);
            return;
        }
        for(int i=pos;i<nums.size();i++) {
            swap(nums[i],nums[pos]);
            generate(nums,pos +1);
            swap(nums[i],nums[pos]);                    
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> result;
        generate(nums,0);
        return soln;
    }
};
