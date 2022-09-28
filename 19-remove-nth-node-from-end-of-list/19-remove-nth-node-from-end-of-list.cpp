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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        
        while(temp)
        {
            size++;
            temp = temp->next;
        }
        
        temp = head;
        int t = size - n - 1;
        
        if(size == n)
        {
             head = temp->next; 
            return head;
        }
          
        while(t>0)
        {
            temp = temp->next; 
            t--;
        }
        
        if(temp->next)
        temp->next = temp->next->next;
        else
            temp->next = NULL;
        
        return head;
    }
};