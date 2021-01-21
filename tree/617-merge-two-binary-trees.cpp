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
    TreeNode* merge(TreeNode* t1, TreeNode* t2) {        
        if(t1==NULL && t2==NULL)
            return NULL;
        else if(t2 == NULL)
            ;
        else if(t1 == NULL) {
            t1 = new TreeNode(t2->val);            
        } else {
            t1->val += t2->val;
        }        
        
        TreeNode* node = merge(t1->left, t2==NULL?NULL:t2->left);
        t1->left = node;        
                
        TreeNode* node2 = merge(t1->right,t2==NULL?NULL:t2->right);
        t1->right = node2;
        return t1;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
       TreeNode* node = merge(t1,t2) ;
       return node;        
    }
};
