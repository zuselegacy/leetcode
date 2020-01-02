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
        no.push(root);
        while(!no.empty()) {
            TreeNode* node = no.top();
            no.pop();
            if(node!=NULL){
                list.push_back(node->val);
                no.push(node->right) ;
                no.push(node->left);
            }     
        }
        return list;
        
    }
};
