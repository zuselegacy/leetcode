/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        while(nodeA != nodeB) {
            if(nodeA->next== NULL && nodeB->next == NULL)
                return NULL;
            if(nodeA->next)
                nodeA = nodeA->next;
            else
                nodeA = headB;
            if(nodeB->next)
                nodeB = nodeB->next;
            else
                nodeB = headA;
        }
        return nodeA;

    }
};
