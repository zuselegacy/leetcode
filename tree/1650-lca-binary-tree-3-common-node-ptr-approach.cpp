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
// use a slow/fast pointer to find common node in linked list
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* pStart = p;
        Node* qStart = q;
        while(p->val != q->val) {
            p = p->parent;
            if(p == NULL)
                p = qStart;
            q = q->parent;
            if(q == NULL)
                q = pStart;            
        }
        return p;        
    }
};
