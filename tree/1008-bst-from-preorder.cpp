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
    TreeNode* constructTree(vector<int>& preorder,int low, int high) {
        if(low > high)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[low]);
        int i = low + 1;
        for(i=low + 1;i<=high;i++) {
            if(preorder[i]> preorder[low])
                break;
        }        
        root->left = constructTree(preorder, low + 1, i-1);
        root->right = constructTree(preorder, i, high);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {        
        return constructTree(preorder, 0, preorder.size() -1);
        
    }
};
