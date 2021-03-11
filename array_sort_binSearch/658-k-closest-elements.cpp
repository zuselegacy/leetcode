class Solution {
public:
    int binSearch(vector<int>& arr, int x) {
        int low = 0, high = arr.size();
        while(low < high) {
            int mid = low + (high-low)/2;
            if(arr[mid] >=  x)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = binSearch(arr, x);
        int left = max(0,index -k);
        int right = std::min((int)index + k,(int) arr.size()-1);        
        while(right - left +1 > k) {
            int leftDiff = abs(arr[left] -x);           
            int rightDiff = abs(arr[right] - x);
            if(leftDiff <= rightDiff) 
                right--;
             else   
                left++;                            
        }        
        return vector<int>(arr.begin() + left,arr.begin() + right +1 );         
    }
};
