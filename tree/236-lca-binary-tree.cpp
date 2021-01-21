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
    bool lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return false;
        bool result1 = lca(root->left, p, q);
        if(lcaNode)
            return true;
        bool result2  = lca(root->right, p ,q);
        if(lcaNode)
            return true;
        
        if(result1 && result2) {
            lcaNode = root;
            return true;
        } else {
            bool result3 = p->val == root->val || q->val == root->val;
            if(result1 + result2 + result3 == 2)                 
                    lcaNode = root;                                
            return result1 || result2 || result3;
        }        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca(root,p,q);
        return lcaNode;
        
    }
    TreeNode* lcaNode = NULL;
};
