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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> no;
        vector<int> list;
        while(true) {
            while(root!=NULL) {
                no.push(root);
                root = root->left;
            }
            if(no.empty()) {
                break;
            }
            TreeNode* node = no.top();
            no.pop();
            list.push_back(node->val);
            root = node->right;
        }
        return list;        
    }
};
