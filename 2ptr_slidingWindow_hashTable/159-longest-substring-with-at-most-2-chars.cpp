// classic sliding window
// use counter instead of hashmap.size() for check
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char,int> charMap;
        int maxCount = 0;
        int left =0, right = 0;
        int count =0;
        while(right<s.size()) {
            charMap[s[right]]++;
            if(charMap[s[right]]==1)
                count++;           
            while(count>2) {
                charMap[s[left]]--;
                if(charMap[s[left]] == 0)
                    count--;                    
                left++;                 
            }
            maxCount = max(maxCount,right-left+1);
            right++;
        }
        return maxCount;
        
    }
};
