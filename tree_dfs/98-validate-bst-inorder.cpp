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
    bool inorder(TreeNode* root, int* prev) {
        if(root == NULL)
            return true;                 
        if(!inorder(root->left, prev))
            return false;
        if(*prev!=-1 && root->val <= *prev)
            return false;
        *prev = root->val;
        return inorder(root->right,prev);                
    }
    bool isValidBST(TreeNode* root) {
        int prev = -1;
        return inorder(root,&prev);
        
    }
};
