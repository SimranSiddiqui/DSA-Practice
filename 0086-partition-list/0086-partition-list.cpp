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
    ListNode* partition(ListNode* head, int x) {
        queue<int> qSmall, qBig;
        ListNode* temp = head;
        
        while(temp)
        {
            if(temp->val < x)
                qSmall.push(temp->val);
            else
                qBig.push(temp->val);
            
            temp = temp->next;
        }
        
        temp = head;
        while(!qSmall.empty())
        {
            int val = qSmall.front();
            qSmall.pop();
            
            temp->val = val;
            temp = temp->next;
        }
        while(!qBig.empty())
        {
            int val = qBig.front();
            qBig.pop();
            
            temp->val = val;
            temp = temp->next;
        }
        
        return head;
    }
};