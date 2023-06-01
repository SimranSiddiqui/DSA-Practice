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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++)
        {
            ListNode* head = lists[i];
            
            while(head != NULL)
            {
                pq.push(head->val);
                head = head->next;
            }
        }
        
        if(!pq.size())
            return NULL;
        
        ListNode* ans = new ListNode(pq.top());
        pq.pop();
        ListNode* temp = ans;
        while(!pq.empty())
        {
            ListNode* curr = new ListNode(pq.top());
            pq.pop();
            
            temp->next = curr;
            temp = temp->next;
        }
        
        return ans;
    }
};