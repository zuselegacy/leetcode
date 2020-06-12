// inner loops to move ptr to a valid comparable pointer
// all checks done inside the outer loop - we should both run out of valid chars at the same time or if both present, should match
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size()-1;
        int j = T.size()-1;        
        int skipS=0;
        int skipT=0;
        while(i>=0 || j>=0) {
            while(i>=0) {
                if(S[i] =='#') {
                    skipS++;                    
                    i--;
                } else if(skipS>0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }
            while(j>=0) {
                if(T[j] =='#') {
                    skipT++;
                    j--;
                } else if(skipT>0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }
          if(i>=0 && j>=0 && S[i]!=T[j]) {
             return false ;          
          } else if((i<0) != (j<0)) {
              return false;
          }
            i--;
            j--;
            
        }
      return true;
        
        
    }
};

