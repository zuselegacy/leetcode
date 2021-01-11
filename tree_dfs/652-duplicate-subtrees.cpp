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
#include<map>
class Solution {
public:
    string serialize(TreeNode* node) {
        if(node == NULL)
            return "$";
        string result = string("#") + std::to_string(node->val);
        result = result + serialize(node->left) + serialize(node->right);        
        if(++treeCount[result] == 2)
            dupTrees.push_back(node);
        return result;
            
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return dupTrees;
    }
    std::map<string,int> treeCount;
    vector<TreeNode*> dupTrees;
};
