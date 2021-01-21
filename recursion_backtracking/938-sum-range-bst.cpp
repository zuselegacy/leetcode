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
    int sumTree(TreeNode* root, int L, int R) {
        if(root == NULL){
            return 0;
        }
        if(root->val>=L && root->val <=R) {
           return root->val + sumTree(root->left,L,R) +sumTree(root->right,L,R);
        } else if(root->val <L) {
            return sumTree(root->right,L,R);
        }        
        else {
            return sumTree(root->left,L,R);
        }
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        return sumTree(root,L,R);
    }
};
