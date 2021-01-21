/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorder(TreeNode* root, TreeNode* p, bool* found) {
        if(root == NULL)
            return root;
        TreeNode* next = inorder(root->left,p,found);    
        if(next) 
            return next;
        
        if(root == p)
            *found = true;
        else if(*found)
            return root;
        
        return inorder(root->right,p,found);      
        
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool found = false;
        return inorder(root,p,&found);
        
    }
};
