class Solution {
public:
    long long numberOfWays(string s) {
        long noOf0=0;
        long noOf1=0;
        long noOf01=0;
        long noOf10=0;
        long long total = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '1') {
                noOf1++;
                noOf01 += noOf0;
                total += noOf10;
            } else {
                noOf0++;
                noOf10 += noOf1;
                total += noOf01;
            }
        }
        return total;
                            
    }
};
