#include <iostream>
class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        int freqMap[26] = {0};
        for(int i=0;i<s1.size();i++){
            freqMap[s1[i]-'a']++;
        }
        int left=0, right=0;
        while(right<s2.size()) {
            int c = s2[right]-'a';
            freqMap[c]--;
            // invalid condition
            while(freqMap[c]<0) {
                freqMap[s2[left]-'a']++;
                left++;
            }

        if(right-left +1 == s1.size()) {
            return true;
        }
        right++;
        }
        return false;

    }
};
