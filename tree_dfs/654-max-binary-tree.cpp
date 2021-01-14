/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findMax(vector<int>& nums) {
        int max = nums[0];
        int index = 0;
        for(int i=1;i<nums.size();i++) {
            if(nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        return index;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == NULL)
            return NULL;
        int index = findMax(nums);
        TreeNode* root = new TreeNode(nums[index]);
        vector<int> left(nums.begin(), nums.begin() + index);
        vector<int> right(nums.begin()+index+1,nums.end());
        
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
        
    }
};
