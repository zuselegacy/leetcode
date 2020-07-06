class Solution {
public:
    int titleToNumber(string s) {
        long total = 0;
        for(int i=0;i<s.size();i++) {
            total = total *26;
            total = total + s[i]- 'A' +1;
        }
        return total;        
    }
};
