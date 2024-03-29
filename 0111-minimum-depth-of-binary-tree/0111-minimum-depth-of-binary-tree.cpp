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
    int minDepth(TreeNode* root) {
       
        queue<TreeNode* > q;
        if(root)
        q.push(root);
        int level =0;
        
        while(!q.empty())
        {
            int n = q.size();
            level++;
            for(int i=0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(!node->left && !node->right)
                return level;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        
        return level;
    }
};