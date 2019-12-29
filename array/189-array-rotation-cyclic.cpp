class Solution {
public:
    int gcd(int x, int y) {
        if(y==0){
            return x;
        }
        return gcd(y,x%y);
    }
    void swap(int& x,int& y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    void rotate(vector<int>& nums, int k) {
        k = (k%nums.size());
        const int cycleCount = gcd(nums.size(),k);
        
        for(int i=0;i<cycleCount;i++) {        
            int pos = i;
            int tmp = nums[pos];            
            do {
                int newPos = (pos+k)% nums.size();
                swap(tmp,nums[newPos]);
                pos = newPos; 
            } while(pos != i);
        }
        
    }
};
