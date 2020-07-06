class Solution {
public:
    bool isQuad(vector<int>& arr, int target) {
        vector<int>::iterator start = std::lower_bound(arr.begin(),arr.end(),target);
        if(start == arr.end()) {
            return false;
        }
        vector<int>::iterator end = std::upper_bound(arr.begin(),arr.end(),target);
        if(end-start >arr.size()/4)
            return true;
        else
            return false;                
    }
            
    int findSpecialInteger(vector<int>& arr) {
        int index = arr.size()/4;
        if(isQuad(arr,arr[index]))
            return arr[index];
        index = arr.size()/2;
        if(isQuad(arr,arr[index]))
            return arr[index];
        index = (3*arr.size())/2;
        return arr[index];                
        
    }
};
