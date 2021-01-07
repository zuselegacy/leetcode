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
    bool compareTree(TreeNode* tree1,TreeNode* tree2) {
       if(tree1 == NULL && tree2 == NULL) 
           return true;
        else if(tree1 == NULL || tree2==NULL)
           return false;
        else                          
           return (tree1->val == tree2->val) && compareTree(tree1->left,tree2->left) && compareTree(tree1->right, tree2->right);        
    }
    
    bool traverseAndCompare(TreeNode* s, TreeNode* t) {
        if(compareTree(s,t))
            return true;
        if(s) {            
            if(traverseAndCompare(s->left,t))
                return true;                
            if(traverseAndCompare(s->right,t))
                return true;
        }
        return false;      
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
       return traverseAndCompare(s,t);
    }
};
