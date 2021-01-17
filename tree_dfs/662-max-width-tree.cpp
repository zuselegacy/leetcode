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
    void preorder(TreeNode* root, int level, unsigned long index) {
        if(root == NULL)
            return;
        if(levelMap.find(level) == levelMap.end()) {
            levelMap[level] = index;
        } else {
            maxWidth = max(maxWidth, int(index - levelMap[level] + 1));            
        }
        preorder(root->left,level + 1, index *2);
        preorder(root->right,level + 1, index *2 + 1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        preorder(root, 0, 1);
        return maxWidth;        
    }
    map<int,int> levelMap;
    int maxWidth = 1;
};
