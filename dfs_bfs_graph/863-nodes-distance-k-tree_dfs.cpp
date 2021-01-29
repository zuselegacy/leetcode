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
    void buildGraph(TreeNode* root) {
        if(root == NULL)
            return;
        if(root->left) 
            parent[root->left] = root;
        if(root->right)
            parent[root->right] = root;
        buildGraph(root->left);
        buildGraph(root->right);        
    }
    void dfs(TreeNode* root, TreeNode* prev, int dist, int K) {        
        if(root == NULL)
            return;
        if(dist == K) {
            result.push_back(root->val);
            return;            
        }
        if(root->left != prev)
            dfs(root->left, root, dist +1, K);
        if(root->right != prev)
            dfs(root->right,root, dist +1, K);
        if(parent.find(root)!= parent.end() && parent[root] != prev)
            dfs(parent[root], root, dist +1, K);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        buildGraph(root);
        dfs(target, NULL, 0, K);
        return result;                            
    }
    map<TreeNode*,TreeNode*> parent;
    vector<int> result;

};
