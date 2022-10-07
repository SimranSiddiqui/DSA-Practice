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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val)
        {
            head = head->next;
        }
        
        if(!head || !head->next)
            return head;
        
        ListNode *t1 = head;
        ListNode *t2 = head->next;
        
        while(t2)
        {
            if(t2->next == NULL && t2->val == val)
            {
                t1->next = NULL;
                t2 = NULL;
                break;
            }
            while(t2 && t2->val == val)
            {
               t2 = t2->next;
            }
            
            t1->next = t2;
            t1 = t2;
            if(t1)
            t2 = t1->next;
        }
        
        return head;
    }
};