class Solution {
public:
    void reverse(vector<char>&s, int start, int end) {
        while(start<end) {
            char tmp = s[start];
            s[start] = s[end];
            s[end]= tmp;
            start++;
            end--;
        }
    }
    void reverseWords(vector<char>& s) {
        reverse(s,0,s.size()-1);
        int start = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] == ' ') {
                reverse(s,start,i-1);
                start = i + 1;
            }            
        }
        reverse(s,start,s.size()-1);
    }
};
