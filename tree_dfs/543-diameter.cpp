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
    // returns maxDepth at root, computes max diameter at root
    // postorder
    int find(TreeNode* root, int* ans) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) {            
            return 0;
        }
        int ldepth=0,rdepth = 0;
        int localDiameter = 0;
        if(root->left) {
            ldepth = find(root->left, ans);
            localDiameter++;
        }
        if(root->right) {
            rdepth = find(root->right, ans);
            localDiameter++;
        }
        localDiameter = localDiameter + ldepth + rdepth;
        *ans = max(*ans, localDiameter);
        return (max(ldepth,rdepth) +1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
  //      if(root == NULL)
   //         return 0;
        find(root,&ans);
        return ans;        
    }
};
