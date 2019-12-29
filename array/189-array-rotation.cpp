class Solution {
public:
    void reverse(vector<int>& nums,  int start, int end) {
        while(start < end) {
            nums[start] = nums[start] ^ nums[end];
            nums[end] = nums[start] ^ nums[end];
            nums[start] = nums[start] ^ nums[end];
            start++;
            end--;
        }
    }
    void print(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            cout<<nums[i];
        }
        cout<<endl;
    }
    void rotate(vector<int>& nums, int k) {
        int cut = (k%nums.size());
        if(cut!=0) {
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,cut-1);
        reverse(nums,cut,nums.size()-1);
        }
        
    }
};
