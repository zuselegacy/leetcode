class Solution {
public:
    vector<vector<int>> soln;

    void generate(vector<int>& nums,int pos) {
        if(pos==nums.size()) {           
            soln.push_back(nums);
            return;
        }
        set<int> posSet;
        for(int i=pos;i<nums.size();i++) {            
            if(posSet.find(nums[i]) !=posSet.end())
                continue; 
            else
                posSet.insert(nums[i]);            
               swap(nums[i],nums[pos]);
               generate(nums,pos+1);
               swap(nums[i],nums[pos]); 
            
            }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {        
        generate(nums,0);
        return soln;
    }
};
