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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n,0));
        
        ListNode *node = head;
        int left =0, right = n-1, top = 0, bottom = m-1;
        
        while(left<=right && top<=bottom)
        {
            
            for(int i=left;i<=right && top<=bottom;i++)
            {
                int x =-1;
                if(node)
                x = node->val;
            
                ans[top][i] = x;
                
                if(node)
                node = node->next;
            }
            top++;
            
             
            for(int i=top;i<=bottom && left<=right;i++)
            {
                int x =-1;
                if(node)
                x = node->val;
            
                ans[i][right] = x;
                
                if(node)
                node = node->next;
            }
            right--;
            
            for(int i=right;i>=left && top<=bottom;i--)
            {
                int x =-1;
                if(node)
                x = node->val;
            
                ans[bottom][i] = x;
                
                if(node)
                node = node->next;
            }
            bottom--;
            
            for(int i=bottom;i>=top && left<=right;i--)
            {
                int x =-1;
                if(node)
                x = node->val;
            
                ans[i][left] = x;
                
                if(node)
                node = node->next;
            }
            left++;     
        }
        
        return ans;
        
    }
};