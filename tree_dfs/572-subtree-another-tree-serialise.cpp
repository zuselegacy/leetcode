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
    string serialize(TreeNode* node) {
        if(node == NULL) 
            return "$";
        string result = string("#") + std::to_string(node->val);
        return result + serialize(node->left) + serialize(node->right);        
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string str = serialize(s);
        string ptn = serialize(t);
        if(str.find(ptn) == string::npos)
            return false;
        else
            return true;                
    }
};
