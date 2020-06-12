// very similar to perm in string
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int freqMap[26] = {0};
        vector<int> result;
        for(int i=0;i<p.size();i++){
            freqMap[p[i]-'a']++;
        }
        int left=0, right=0;       
        while(right<s.size()) {
            int c = s[right]-'a';                        
            freqMap[c]--;  
            // invalid condition
            while(freqMap[c]<0) {
                freqMap[s[left]-'a']++;
                left++;
            }                        
           if(right-left +1 == p.size()) {
            result.push_back(left);
            }
        right++;            
        }
        return result;
        
    }
};
