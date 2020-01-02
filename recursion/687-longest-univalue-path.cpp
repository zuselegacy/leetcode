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
    int maxNo(int x, int y){
        return x>y?x:y;
    }
    int longPath(TreeNode* root,int* max) {
        if(root == NULL) {
            return -1;
        }
        int left = longPath(root->left,max);
        int right = longPath(root->right,max);
        int result =0;
        int curChain=0;
        if(left!= -1 && root->left->val == root->val) {
            left = left +1;
        } else {
            left = 0;
        }
        if(right!=-1 && root->right->val == root->val){
            right =right +1;
            
        }else {
            right =0;
        }
        *max=maxNo(*max,left+right);
        return maxNo(left,right);
    }
    int longestUnivaluePath(TreeNode* root) {
        int max =0;
        longPath(root,&max);
        return max;
        
    }
};
