class Solution {
public:
    void generatePerm(string& s,int pos, vector<string>* soln) {
        if(pos == s.size()) {
            soln->push_back(s);
            return;
        }
        if(s[pos] >=48 &&s[pos] <=57) {
            generatePerm(s,pos +1 , soln);
            return;
        } else {
            generatePerm(s,pos+1,soln);
            if(s[pos] >= 97) {
                s[pos] = s[pos] -32;
            } else {
                s[pos] = s[pos] + 32;
            }
            generatePerm(s,pos+1,soln);
            return;
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> soln;
        generatePerm(S,0,&soln);
        return soln;        
    }
};
