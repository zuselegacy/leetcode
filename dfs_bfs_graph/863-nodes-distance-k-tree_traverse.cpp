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
    void depth(TreeNode* root, int K, int currDepth) {
        if(root == NULL)
            return;
        if(currDepth == K) {
            result.push_back(root->val);
            return;
        }
        depth(root->left, K, currDepth +1);
        depth(root->right, K, currDepth +1);            
    }
    
    int dfs(TreeNode* root, TreeNode* target, int K) {        
        if(root == NULL)
            return 0;
        if(root->val == target->val) {
            depth(root, K, 0 );
            return 1;
        } 
        int left = dfs(root->left, target, K);
        if(left !=0) {
            if(left == K) {
                result.push_back(root->val);
                return 0;
            } else {                    
                depth(root->right, K, left +1);
                return left +1;
            }
        }
        int right = dfs(root->right, target, K);
        if(right != 0) {
           if(right == K) {
                result.push_back(root->val);
                return 0;
            } else {
                depth(root->left, K, right + 1);
                return right + 1;
            }
        }
        return 0;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, target, K);
        return result;                            
    }
    vector<int> result;

};
