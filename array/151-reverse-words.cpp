class Solution {
public:
   void cleanSpace(string& s) {
       int i=0,j=0;
       while(j<s.size()) {
           while(j<s.size() && s[j] == ' ') {
               j++;
           }
           bool wordSeen = false;
           while(j<s.size() && s[j] != ' ') {
               wordSeen = true;
               s[i] = s[j];
               i++;
               j++;
           }
           if(wordSeen) {
           s[i] = ' ';
           i++;
           }
       }
       if(i<s.size()) {
        s.erase(i);
       }
       if(i> 0 && s[i-1] == ' ') {
           s.erase(i-1);
       };
   }
   void reverse(string& s, int start, int end) {
        while(start<end) {
            char tmp = s[start];
            s[start] = s[end];
            s[end]= tmp;
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        cleanSpace(s);
        reverse(s,0,s.size()-1);
        
        int start = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] == ' ') {
                reverse(s,start,i-1);
                start = i + 1;
            }            
        }
        reverse(s,start,s.size()-1);
        return s;
    }
};
