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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        set<Node*> parentNodes;
        while(p) {
            parentNodes.insert(p);
            p = p->parent;
        }
        while(q) {
            if(parentNodes.find(q) != parentNodes.end()) {
                return q;
            }
            q = q->parent;
        }
        return NULL;
    }
};
