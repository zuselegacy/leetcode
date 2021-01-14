/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(node->right) {
            node = node->right;
            while(node->left)
                node = node->left;
            return node;
        }        
        while(node->parent) {
            if(node->parent->left == node)
                return node->parent;
            node = node->parent;
        }
              
        return NULL;
    }
};
