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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* s = NULL;
        ListNode* e = NULL;
        ListNode* temp = list1;
        
        int i = 0;
        while(temp)
        {
            if(i==a-1)
                s = temp;
            if(i == b+1)
                e = temp;
            
            temp = temp->next;
            i++;
        }
        
        temp = list2;
        while(temp->next){
            temp = temp->next;
        }
        
        if(s)
            s->next = list2;
        temp->next = e;
        
        return list1;
    }
};