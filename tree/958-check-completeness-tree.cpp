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
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool seenNull = false;
        while(!q.empty()) {
            if(q.front() == NULL) {                
                seenNull = true;
            }
            else {
                if(seenNull)
                    return false;
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
        }
        return true;        
    }
};
