/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* clone(Node* root) {
        if(root == NULL)
            return NULL;
        NodeCopy* newNode = NULL;
        if(hash.find(root) == hash.end()) {
            newNode = new NodeCopy(root->val);
            hash[root] = newNode;
        }
        newNode = hash[root];
        
        newNode->val = root->val;
        if(root->random == NULL)
            newNode->random = NULL;
        else { 
            if(hash.find(root->random) == hash.end()) {
            NodeCopy* randomNode = new NodeCopy();
            hash[root->random] = randomNode;
         }            
            newNode->random = hash[root->random];
        }
        
        newNode->left = clone(root->left);
        newNode->right = clone(root->right);
        return newNode;
    }
    NodeCopy* copyRandomBinaryTree(Node* root) {
        return clone(root);
    }
    map<Node*,NodeCopy*> hash;
};
