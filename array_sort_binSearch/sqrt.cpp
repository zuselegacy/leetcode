class Solution {
public:
    int mySqrt(int x) {
        if(x == 1)
            return x;
        int low = 1, high = x/2;
        int sqrt = 0;
        while(low<=high) {
            long mid = low + (high-low)/2;
            if(mid*mid == x)
                return mid;
            else if(mid*mid <x) {
                sqrt = mid;
                low = mid + 1;
            } else 
                high = mid - 1;                
        }
        return sqrt;
    }
};
