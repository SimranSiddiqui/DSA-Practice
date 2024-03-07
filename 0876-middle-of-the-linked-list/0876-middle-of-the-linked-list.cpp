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
    ListNode* middleNode(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        int count  = 1;
        ListNode* node = head;
        
        while(node)
        {
            mp[count] = node;
            count++;
            node = node->next;
        }
        
        int mid = ceil(float(count)/2);
        
        return mp[mid];
    }
};