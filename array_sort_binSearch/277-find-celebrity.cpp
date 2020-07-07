/* The knows API is defined for you.
      bool knows(int a, int b); */
#include<iostream>
class Solution {
public:
    int findCelebrity(int n) {
        int left =0, right=n-1;
        while(left<right) {
            if(knows(left,right))
                left++;
            else
                right--;
        }
        cout<<left;
        for(int i=0;i<=n-1;i++){
            if(i!=left && (knows(left,i)||!knows(i,left)))
                return -1;
        }
        return left;
    }
};
