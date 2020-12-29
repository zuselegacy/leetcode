// shrinking window pattern 

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        int low = 1;
        int high = 1000;
        vector<vector<int>> list;
        while(low<=1000 && high >=1) {
            vector<int> soln;
            if(customfunction.f(low,high) == z) {
                soln.push_back(low);
                soln.push_back(high);
                list.push_back(soln);
                low++;
                high--;
            } else if(customfunction.f(low,high) <z){
                low++;                
            } else {
                high--;
            }
        }
        return list;
        
    }
};
