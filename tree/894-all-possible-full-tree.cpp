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
    TreeNode* makeDeepCopy(TreeNode* root) {
        if(root == NULL)
            return NULL;
        TreeNode* newRoot = new TreeNode(0);
        newRoot->left = makeDeepCopy(root->left);
        newRoot->right = makeDeepCopy(root->right);
        return newRoot;
    }
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> result;
        if(N%2==0)
            return result;        
        if(hash.find(N) != hash.end()) 
            return hash[N];
        if(N == 1) {
            result.push_back(new TreeNode(0));
            return result;
        }
        for(int i=2;i<=N;i+=2) {
            vector<TreeNode*> left = allPossibleFBT(i-1);
            vector<TreeNode*> right = allPossibleFBT(N-i);
            for(auto iter1:left) {
                for(auto iter2:right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = makeDeepCopy(iter1);
                    root->right = makeDeepCopy(iter2);
                    result.push_back(root);
                }                    
            }                        
        }
        hash.insert(make_pair(N,result));
        return result;                                
    }
    map<int,vector<TreeNode*>> hash;
};
