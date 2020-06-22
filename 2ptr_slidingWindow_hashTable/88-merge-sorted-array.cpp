class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 =m-1;
        int ptr2 = n-1;
        int dst = m+n-1;
        while(ptr1>=0 && ptr2>=0) {
            nums1[dst] = max(nums1[ptr1],nums2[ptr2]);            
            if(nums1[dst] == nums1[ptr1])
                ptr1--;
            else 
                ptr2--;
            dst--; 
        }
        while(ptr1>=0){
            nums1[dst--] = nums1[ptr1--];            
        }
        while(ptr2>=0) {
            nums1[dst--] = nums2[ptr2--];            
        }
        
    }
};
