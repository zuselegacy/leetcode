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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> no;
        vector<int> list;
        while(true) {
            while(root!=NULL) {
                list.push_back(root->val);                            
                no.push(root);
                root = root->left;
            }
            if(no.empty()) {
                break;
            }
            TreeNode* node = no.top();
            no.pop();
            root = node->right;
        }
        return list; 
        
    }
};
