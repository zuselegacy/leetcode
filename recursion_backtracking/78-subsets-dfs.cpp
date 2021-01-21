class Solution {
public:
    vector<vector<int>>  soln;
    void generate(vector<int>& nums,vector<int>& result,int pos) {
        soln.push_back(result);
        for(int i=pos;i<nums.size();i++) {
            result.push_back(nums[i]);
            generate(nums,result,i+1);
            result.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> result;
        generate(nums,result,0);
        return soln;
    }
};
