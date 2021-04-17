class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
	// for the same right], find:
	// [left1,right] represents a valid window where no of distinct integers = K
	// [left2,right] left2 represents first instance in window where no of distinct integers <K
	// [left1... left2.......right]
        map<int,int> numCount1,numCount2;
        int left1 =0, left2 = 0;
        int right = 0;
        int count = 0;
        while(right < A.size()) {
            numCount1[A[right]]++;
            numCount2[A[right]]++;
            
            while(numCount1.size() > K) {
                numCount1[A[left1]]--;
                if(numCount1[A[left1]] == 0)
                    numCount1.erase(A[left1]);
                left1++;                
            }
            
            while(numCount2.size() >= K) {
                numCount2[A[left2]]--;
                if(numCount2[A[left2]] == 0)
                    numCount2.erase(A[left2]);
                left2++;                
            }
            right++;
            count = count + (left2-left1);            
        }
        return count;
        
    }
};
