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
    void dfs(TreeNode* root,int min, int max) {
        if(root == NULL)
            return;
        V = std::max(V, abs(root->val-min));
        V = std::max(V, abs(root->val-max));
        min = std::min(min, root->val);
        max = std::max(max, root->val);
        dfs(root->left, min, max);
        dfs(root->right, min, max);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL)
            return V;
        dfs(root->left, root->val, root->val);
        dfs(root->right, root->val, root->val);
        return V;
        
    }
    int V = 0;
};
