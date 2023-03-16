/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            bool flag = false;
            vector<int> arr;
            for(int i =0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(!node->left)
                    flag = true;
                else
                {
                    if(flag)
                        return false;
                  q.push(node->left);   
                }
                if(!node->right)
                    flag = true;
                else
                {
                    if(flag)
                        return false;
                    q.push(node->right);   
                }
            }
            
            if(flag)
            {
                while(!q.empty())
                {
                    TreeNode* node = q.front();
                    q.pop();
                    
                    if(node->left)
                        return false;
                    if(node->right)
                        return false;
                }
            }
        }
        
        return true;
    }
};