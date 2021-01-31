/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        queue<Node*> q;
        map<Node*,Node*> translate;
        Node* newNode = new Node();
        translate[node] = newNode;    
        q.push(node);
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            Node* newNode = translate[node];
            newNode->val = node->val;
            for(int i=0;i<node->neighbors.size();i++) {
                Node* neighbor = node->neighbors[i];
                if(translate.find(neighbor) == translate.end()) {
                    Node* newNeighbor = new Node();
                    translate[neighbor] = newNeighbor;
                    q.push(neighbor);
                }
                newNode->neighbors.push_back(translate[neighbor]);
            }                        
        }
        return translate[node];
        
    }    
};
