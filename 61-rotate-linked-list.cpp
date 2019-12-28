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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* end =NULL;
        ListNode* ptr = head;
        int length = 0;
        while(ptr) {
            length++;
            end = ptr;
            ptr = ptr->next;
        }
        if(length == 0) 
            return head;
        k = k%length;
        if(k==0){
            return head;
        }
        ListNode* prev = head;
        ptr = head;
        for(int i=0;i<length;i++) {
            if (i == length-k) {
                end->next = head;
                head = ptr;
                prev->next = NULL;
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};
