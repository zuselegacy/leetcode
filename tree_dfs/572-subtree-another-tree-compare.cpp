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
#include<string>
class Solution {
public:
    bool checkSubTree(TreeNode* main,TreeNode* sub) {
       if(main == NULL && sub == NULL) 
           return true;
        else if(main == NULL || sub==NULL)
           return false;
        else                          
           return (main->val == sub->val) && checkSubTree(main->left,sub->left) && checkSubTree(main->right,sub->right);        
    }
    
    bool traverse(TreeNode* s, TreeNode* t) {
        if(checkSubTree(s,t))
            return true;
        if(s) {            
            if(traverse(s->left,t))
                return true;                
            if(traverse(s->right,t))
                return true;
        }
        return false;        
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
       return traverse(s,t);
    }
};
