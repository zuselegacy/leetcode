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
        if(root == NULL) {
            return 0;
        }
        // process
        int sum = 0;
        if(root->val>=L && root->val <=R) {
           sum = root->val;
        }
        // traverse
        if(L < root->val) {
            sum += sumTree(root->left,L,R);
        }        
        if(R > root->val) {            
            sum += sumTree(root->right,L,R);
        }        
        return sum;
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        return sumTree(root,L,R);
    }
};
