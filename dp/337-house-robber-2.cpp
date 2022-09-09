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
    int rob(TreeNode* root) {
        int withNode = 0,withoutNode=0;
        return walk(root,&withNode,&withoutNode);
    }
    
    int walk(TreeNode* node, int* maxLeft, int* maxRight ) {
        if(node == NULL){
            *maxLeft=0;
            *maxRight=0;
            return 0;
        }
        int leftMaxLeft=0,leftMaxRight=0;
        int rightMaxLeft=0,rightMaxRight=0;
        *maxLeft = walk(node->left,&leftMaxLeft,&leftMaxRight);
        *maxRight = walk(node->right,&rightMaxLeft,&rightMaxRight);
        
        int withNode = node->val + leftMaxLeft + leftMaxRight + rightMaxLeft + rightMaxRight;
        int withoutNode = *maxLeft + *maxRight;
        return (max(withNode,withoutNode));
    }
};
