// classic 2 ptr soln - input is arranged from high to low to high
// output should be low to high
// so we use 2ptr to know which input to process
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i=0,j=A.size()-1;
        vector<int> result(A.size());
        int index = A.size()-1;
        while(i<=j) {
            if(abs(A[i]) > abs(A[j])) {
                result[index] = A[i] *A[i];
                i++;
            } else {
                result[index] = A[j] * A[j];
                j--;
            }
            index--;
        }
        return result;
    }
};
