/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    map<Node*,Node*> table;
    Node* nodeMap(Node* oldNode) {
        if(table.find(oldNode) == table.end()) {
            Node* newNode = new Node(-1);
            table[oldNode] = newNode;            
        }
        return table[oldNode];        
    }
    Node* copyRandomList(Node* head) {
        Node* origHead = head;
        while(head!=NULL) {
            Node* curNode = nodeMap(head);
            curNode->val = head->val;
            if(head->next == NULL) 
                curNode->next = NULL;
            else 
                curNode->next = nodeMap(head->next);
            if(head->random == NULL)
                curNode->random = NULL;
            else
                curNode->random = nodeMap(head->random);
            head = head->next;
        }
        return table.empty()? NULL:table[origHead];
        
    }
};
