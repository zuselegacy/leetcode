class Solution {
public:
    int totalFruit(vector<int>& tree) {
        map<int,int> fruitBasket;
        int maxCount = 0;
        int left =0, right = 0;
        while(right<tree.size()) {
            fruitBasket[tree[right]]++;
            while(fruitBasket.size()>2) {
                fruitBasket[tree[left]]--;
                if(fruitBasket[tree[left]] == 0)
                    fruitBasket.erase(tree[left]);
                left++;
                
            }
            maxCount = max(maxCount,right-left+1);
            right++;
        }
        return maxCount;
            
        
    }
};
