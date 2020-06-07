2ptr - notice the termination condition is '<', since swap of char of itself is idempotent(when array length is odd)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0, j=s.size()-1;
        while(i<j) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }        
    }
};
