/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
#include<iostream>
class Solution {
public:
    Node* dfs(Node* cur, Node* prev) {
        if(cur == NULL)
            return NULL;
        if(prev) {
            prev->next = cur;
            cur->prev = prev;
        }
    
        Node* tmp = cur->next;        
        Node* child = cur;
        if(cur->child != NULL)            
            child = dfs(cur->child,cur);
        if(tmp!=NULL) 
            child = dfs(tmp, child);        
        cur->child = NULL;       
        return child;
    }
    Node* flatten(Node* head) {
        dfs(head,NULL);        
        return head;        
    }
};
