class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;        
        s.push(0);
        int l=INT_MAX,r=INT_MIN;
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i] >= nums[i-1])
                s.push(i);
            else {
                while(s.size() && nums[s.top()] > nums[i] )
                    s.pop();
                int tmp = s.size()?s.top()+1:0;
                l = tmp<l? tmp:l;
                s.push(i);
            }
        }
        if(l == INT_MAX)
            return 0;
        while(s.size())
            s.pop();
        
        s.push(nums.size()-1);
        for(int i=nums.size()-2;i>=0;i--) {
            if(nums[i] <= nums[i+1])
                s.push(i);
            else {
                while(s.size() && nums[s.top()] < nums[i] )
                    s.pop();
                int tmp = s.size()?s.top()-1:nums.size()-1;
                r = tmp>r?tmp:r;
                s.push(i);
            }
        }
        return r-l+1;                
    }
};
