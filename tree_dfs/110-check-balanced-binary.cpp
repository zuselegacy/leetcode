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
    bool checkBalanced(TreeNode* root, int* height) {
        if(root==NULL) {
            *height = 0;
            return true;
        }
        bool leftBalanced = checkBalanced(root->left, height);
        int lHeight = *height;
        if(!leftBalanced)
            return false;
        bool rightBalanced = checkBalanced(root->right, height);
        int rHeight = *height;
        if(!rightBalanced)
            return false;
        if(abs(rHeight - lHeight) <=1) {
            *height = max(lHeight,rHeight) + 1;
            return true;
        }
        return false;        
    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return checkBalanced(root,&height);
        
    }
};
