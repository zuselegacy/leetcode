/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class CompListNode {
    public:
    bool operator()(const ListNode* l1, const ListNode* l2) const {
        return l1->val >  l2->val;
    }    
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,CompListNode> pq;
        for(int i=0;i<lists.size();i++) {
           if(lists[i])
               pq.push(lists[i]);
        }
        
        ListNode* last = NULL;
        ListNode* head = NULL;
        while(!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();
            if(cur->next)
                pq.push(cur->next);
            if(last == NULL)
                head = cur;
            else 
                last->next = cur;
            last = cur;                        
        }
        if(last)
            last->next= NULL;
        return head;
        
    }
};
