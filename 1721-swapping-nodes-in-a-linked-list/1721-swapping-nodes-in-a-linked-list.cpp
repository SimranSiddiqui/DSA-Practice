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
    ListNode* swapNodes(ListNode* head, int k) {
        
        int n =0;
        ListNode *node = head;
        while(node)
        {
           node = node->next;
            n++;
        }
        
        int count =0;
         node = head;
         ListNode *ptr = NULL;
        while(node)
        {
             count++;
            if((count == k || count == n-k+1) && !ptr)
            {
                ptr = node;
            }
            else if(count == n-k+1 || count == k)
            {
                int temp = node->val;
                node->val = ptr->val;
                ptr->val = temp;
            }
            
            node = node->next;
        }
        
        return head;
    }
};