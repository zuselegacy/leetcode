// use min to prevent ugly corner case check
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int p1=0, p2=0, p3=0;
        vector<int> res;
        while(p1<arr1.size()&&p2<arr2.size()&&p3<arr3.size()) {
            if(arr1[p1]==arr2[p2]&&arr2[p2]==arr3[p3]) {
                res.push_back(arr1[p1]);        
            }
            int m=min(arr1[p1], min(arr2[p2], arr3[p3]));
            if(arr1[p1]==m) p1++;
            if(arr2[p2]==m) p2++;
            if(arr3[p3]==m) p3++;            
        }
        return res;
    }
};
