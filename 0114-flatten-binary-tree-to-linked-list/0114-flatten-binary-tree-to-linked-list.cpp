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
    
    void preOrder(TreeNode* root, vector<TreeNode*> &ptrs)
    {
        if(!root)
            return;
        
        ptrs.push_back(root);
        
        preOrder(root->left, ptrs);
        preOrder(root->right, ptrs);
    }
    
    void flatten(TreeNode* root) {
        
        vector<TreeNode*> ptrs; 
        preOrder(root, ptrs);
        
        int n = ptrs.size();
        for(int i=0;i<n-1;i++)
        {
            ptrs[i]->right = ptrs[i+1];
            ptrs[i]->left = NULL;
        }
        
        if(n-1 >= 0)
        ptrs[n-1]->left = ptrs[n-1]->right = NULL;
    }
};