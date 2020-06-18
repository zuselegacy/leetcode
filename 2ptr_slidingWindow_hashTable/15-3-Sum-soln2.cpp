class Solution {
public:
    set<pair<int,int>> interval; 
    vector<vector<int>> result;
    
    void twoSum(int sum, int start, vector<int>& nums) {
        set<int> foundNum;
        set<int> foundSoln;
        for(int i= start;i<nums.size();i++) {  
            if(foundSoln.find(nums[i])!=foundSoln.end())
                continue;
            int compliment = sum - nums[i];
            if(foundNum.find(compliment)!=foundNum.end()) {
                foundSoln.insert(nums[i]);
                foundSoln.insert(compliment);
                int minI = min(-sum,min(nums[i],compliment));
                int maxI = max(-sum,max(nums[i],compliment));
                pair<int,int> intervalI(minI,maxI);
                if(interval.find(intervalI)==interval.end()) {
                    vector<int> resultI {-sum,nums[i],compliment};
                    result.push_back(resultI);
                    interval.insert(intervalI);                        
                }                
                
            }
            foundNum.insert(nums[i]);            
            
        }
        
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<int> procNo;
        for(int i=0;i<nums.size();i++) {
            if(procNo.find(nums[i])==procNo.end()) {
               twoSum(-nums[i],i+1,nums);              
            }
            procNo.insert(nums[i]);
        }
        return result;                        
        
    }
};
