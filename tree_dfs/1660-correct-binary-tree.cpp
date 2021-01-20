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
#include<queue>
#include<iostream>
class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        if(root == NULL)
            return root;
        
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push(make_pair(root,root));
        
        while(!q.empty()) {
            int levelSize = q.size();
            set<TreeNode*> seenNodes;
            
            for(int i=0;i<levelSize;i++) {
                TreeNode* node = q.front().first;
                TreeNode* parent = q.front().second;
                q.pop();
                if(seenNodes.find(node->right) == seenNodes.end()) {
                   if(node->right)
                       q.push(make_pair(node->right,node));
                    if(node->left)
                        q.push(make_pair(node->left,node));
                } else {
                    if(parent->left == node)
                        parent->left = NULL;
                    else
                        parent->right = NULL;
                    break;
                }
                seenNodes.insert(node);
            }
        }
        return root;                      
    }
};
