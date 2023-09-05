/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node* tempOrig;
        Node* tempNew;
        Node* headNew = head;
        unordered_map<Node*, Node*> mp;
        tempNew = headNew = new Node(head->val);
        tempOrig = head;
        
        while(tempOrig->next)
        {
            mp[tempOrig] = tempNew;
            Node* curr = new Node(tempOrig->next->val);
            tempNew->next = curr;
            tempNew = tempNew->next;
            tempOrig = tempOrig->next;
        }
        
        mp[tempOrig] = tempNew;
        tempNew = headNew;
        tempOrig = head;
        
        while(tempNew)
        {
            tempNew->random = mp[tempOrig->random];
            tempNew = tempNew->next;
            tempOrig = tempOrig->next;
        }
        
        return headNew;
    }
};