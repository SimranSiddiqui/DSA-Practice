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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        
        ListNode *ptr1 = head, *ptr2 = head->next;
        
        while(ptr1 && ptr2)
        {
            int temp = ptr1->val;
            ptr1->val = ptr2->val;
            ptr2->val = temp;
            
            ptr1 = ptr2->next;
            if(ptr1)
                ptr2 = ptr1->next;
        }
        
        return head;
    }
};