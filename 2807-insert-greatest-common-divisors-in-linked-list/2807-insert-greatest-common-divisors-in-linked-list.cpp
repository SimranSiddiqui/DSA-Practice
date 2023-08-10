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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        
        while(temp && temp->next)
        {
            int hcf = __gcd(temp->val, temp->next->val);
            ListNode* hcfNode = new ListNode(hcf);
            
            ListNode* tempNext = temp->next;
            temp->next = hcfNode;
            hcfNode->next = tempNext;
            
            temp = temp->next->next;
        }
        
        return head;
    }
};