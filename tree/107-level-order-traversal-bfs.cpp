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
    void bfs(TreeNode* root, vector<vector<int>>& result) {
        if(root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> levelList;
            for(int i=0;i<size;i++) {
                TreeNode* cur = q.front();
                q.pop();
                levelList.push_back(cur->val);
                if(cur->left)
                   q.push(cur->left);
                if(cur->right)
                   q.push(cur->right);                            
            }
            result.push_back(levelList);                                             
        }                   
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        bfs(root, result);
        std::reverse(result.begin(),result.end());
        return result;        
    }
};
