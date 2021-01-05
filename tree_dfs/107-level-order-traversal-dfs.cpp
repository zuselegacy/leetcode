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
#include<algorithm>
class Solution {
public:
    void dfs(TreeNode* root, int level, vector<vector<int>>& result) {
        if(root == NULL) return;        
        if(result.size() == level) {
            vector<int> newList;
            result.push_back(newList);
        }
        result[level].push_back(root->val);
        dfs(root->left, level+1, result);
        dfs(root->right, level+1, result);        
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        std::reverse(result.begin(),result.end());
        return result;
        
    }
};
