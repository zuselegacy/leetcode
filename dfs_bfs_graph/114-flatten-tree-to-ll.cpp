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
    TreeNode* dfs(TreeNode* cur, TreeNode* parent) {
        if(parent)
            parent->right = cur;
        TreeNode* left = cur->left;
        TreeNode* right = cur->right;
        cur->left = NULL;
        TreeNode* last = cur;
        if(left)
            last = dfs(left, cur);
        if(right)
            last = dfs(right, last);
        return last;            
    }
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        dfs(root, NULL);                
    }
};
