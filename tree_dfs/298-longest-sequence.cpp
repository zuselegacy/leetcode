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
    void search(TreeNode* root, int prevValue, int prevLen) {
        if(root == NULL)
            return;
        if(root->val == prevValue + 1)
            ++prevLen;            
        else
            prevLen = 1;
        longest = max(longest, prevLen);
        search(root->left,root->val,prevLen);
        search(root->right,root->val,prevLen);
        
    }
    int longestConsecutive(TreeNode* root) {
        if(!root)
            return 0;
        search(root->left, root->val,1 );
        search(root->right, root->val,1 );
        return longest;
        
    }
    int longest = 1;
};
