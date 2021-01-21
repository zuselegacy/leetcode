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
    int kth(TreeNode* root,int* k) {
        if(root == NULL)
            return -1;
        int no = kth(root->left,k);
        if(no!=-1) {
            return no;
        }
        *k=*k-1;
        if(*k==0) {
            return root->val;            
        }
        return kth(root->right,k);        

    }
    int kthSmallest(TreeNode* root, int k) {
        return kth(root,&k);
        
    }
};
