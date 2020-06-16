class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        std::sort(A.begin(),A.end());
        int left =0, right = A.size()-1;
        int S = INT_MIN;

        while(left<right) {
            if(A[left] + A[right] >= K) {
                right--;
            } else {
                S = max(S,A[left] + A[right]);
                left++;
            }
        }
        return (S==INT_MIN?-1:S);        
  
    }
};
