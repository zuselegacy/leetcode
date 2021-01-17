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
    int bfs(TreeNode* root) {
        queue<pair<unsigned long,TreeNode*>> q;
        int maxWidth = 0;
        if(root!= NULL)
            q.push(make_pair(1,root));
        while(!q.empty()) {
            int size = q.size();
            unsigned long leftMost = 0;
            unsigned long rightMost = 0;
            for(int i=0;i<size;i++) {
                if(i==0)
                    leftMost = q.front().first;
                if(i==size-1)
                    rightMost = q.front().first;                    
                if(q.front().second->left != NULL)
                    q.push(make_pair(q.front().first*2,q.front().second->left));
                if(q.front().second->right != NULL)
                    q.push(make_pair(q.front().first*2 + 1,q.front().second->right));
                q.pop();                                
            }
            maxWidth = std::max(maxWidth,(int) (rightMost-leftMost+1));
        }
        return maxWidth;
    }
    int widthOfBinaryTree(TreeNode* root) {
        return bfs(root);        
    }    
};
