class Solution {
public:
    vector<vector<int>> soln;
    bool validChoice(int num,const vector<int>& perm) {
        for(int i=0;i<perm.size();i++) {
            if(perm[i] == num)
                return false;
        }
        return true;
    }
    void generate(vector<int>& nums,vector<int>& perm) {
        if(perm.size()==nums.size()) {
            soln.push_back(perm);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(validChoice(nums[i],perm)) {
                perm.push_back(nums[i]);
                generate(nums,perm);
                perm.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> result;
        generate(nums,result);
        return soln;
    }
};
