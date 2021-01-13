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
#include<iostream>
class Solution {
public:
    bool checkNode(TreeNode* root, int lower, int upper) {
        if(root == NULL)
            return true;
        bool curNode = true;
        if(lower != -1)
            curNode = root->val > lower;
        if(upper != -1)
            curNode = curNode && root->val < upper;
        return curNode && 
            checkNode(root->left,lower,root->val) &&
            checkNode(root->right,root->val,upper);                    
    }
    bool isValidBST(TreeNode* root) {
        return checkNode(root,-1,-1);
        
    }
};
