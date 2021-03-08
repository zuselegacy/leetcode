class Solution {
public:
    // closed interval approach
    int mySqrt(int x) {
       int low = 0, high = x;       
        while(low <= high) {            
            long mid = low + (high-low)/2;
            if(mid*mid <= x)
                low = mid+1;
            else                
                high = mid - 1;            
        }
        return high;
    }

    // open close interval approach
    int mySqrt(int x) {   
        int low = 0 , high = x;
        while(low < high) {            
            long mid = low + (high-low)/2;
            if(mid*mid <= x)
                low = mid + 1;
            else                
                high = mid;
        }
        if(low<x)
            return low - 1;
        else {
            // post processing - evaluate last ekement if left points to it
            if(low*low <= x)
                return low;
            else
                return low - 1;
                
        }
    }
};
