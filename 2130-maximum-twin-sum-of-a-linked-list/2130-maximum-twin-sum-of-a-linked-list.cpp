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
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode*ptr = NULL;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            ptr = slow;
        }
        
        ListNode *temp = NULL;
        
        
        do
        {
           temp = slow->next;
           slow->next = ptr;
           ptr = slow;
           slow = temp;
        }while(temp);
        
        int maxi = INT_MIN;
        
        while(ptr->next != head)
        {
            maxi = max(ptr->val+head->val, maxi);
            head = head->next;
            ptr = ptr->next;
        }
        
        return maxi;
    }
};