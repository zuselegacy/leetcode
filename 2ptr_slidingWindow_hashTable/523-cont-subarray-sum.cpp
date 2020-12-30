class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> map;
        map[0] = -1;
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            sum = sum + nums[i];              
            if(k!=0) {
              sum = sum%k;
            }
            if(map.find(sum)!=map.end() ) {
                if(i-map[sum] > 1)
                   return true;
            } else {
                map[sum] = i;
            }            
        }
        return false; 
        
        
    }
};
