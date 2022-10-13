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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next == NULL)
            return NULL;
        
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode* temp = NULL;
        
        while(fast && fast->next)
        {            
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;;
        }
        
        temp->next = temp->next->next;
        
        return head;
    }
};