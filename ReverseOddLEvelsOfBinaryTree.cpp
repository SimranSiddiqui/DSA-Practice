class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        stack<int> revValues;
        queue<TreeNode*> q;
        int count=0;
        
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                    if(count%2==0)
                    revValues.push(node->left->val);
                  
                }
                if(node->right)
                {
                    q.push(node->right);
                    if(count%2==0)
                    revValues.push(node->right->val);
                }
                
                if(count%2!=0)
                {
                   node->val = revValues.top();
                   revValues.pop();  
                }
                
               
            }
            count++;
        }
        
        return root;
        
    }
};
