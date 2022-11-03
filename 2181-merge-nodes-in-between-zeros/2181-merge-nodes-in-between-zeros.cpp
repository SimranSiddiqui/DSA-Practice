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
    ListNode* mergeNodes(ListNode* head) {
        if(!head || !head->next)
            return NULL;      
        
        int sum =0;
        ListNode *node = head->next;
        ListNode *ptr = head;
        while(node)
        {
            if(!node->next)
            {
                ptr->val = sum;
                ptr->next = NULL;
                break;
            }
            else if(node->val == 0 )
            {
                ptr->val = sum;
                ptr->next = node;
                ptr = node;
                node = node->next;
                sum =0;
            }
            else
            {
                sum += node->val;
                node = node->next;
            }
        }
        
        return head;
    }
};