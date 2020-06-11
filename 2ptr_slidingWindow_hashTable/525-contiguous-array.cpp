class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen=0;
        map<int,int> sumIndex;
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) 
                sum--;
             else
                 sum++;
            if(sum==0) {
                maxLen = max(maxLen,i+1);
            } else if(sumIndex.find(sum)!=sumIndex.end()) {
                maxLen = max(maxLen, i-sumIndex[sum]); 
            } else {
                sumIndex[sum] =i;
            }
        }
        return maxLen;        
    }
};


// soln improved - init hashmap with inital condition
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen=0;
        map<int,int> sumIndex;
        int sum=0;
        sumIndex[0] = -1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0)
                sum--;
             else
                 sum++;
            if(sumIndex.find(sum)!=sumIndex.end()) {
                maxLen = max(maxLen, i-sumIndex[sum]);
            } else {
                sumIndex[sum] =i;
            }
        }
        return maxLen;
    }
};
