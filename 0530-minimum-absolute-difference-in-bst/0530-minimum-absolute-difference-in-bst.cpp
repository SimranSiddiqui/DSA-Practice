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
    void traversal(TreeNode* root, vector<int>& inorder)
    {
        if(!root)
            return;
        
        traversal(root->left, inorder);
        inorder.push_back(root->val);
        traversal(root->right, inorder);
    }
    
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> inorder;
        
        traversal(root, inorder);
        int ans = INT_MAX;
        
        for(int i=1;i<inorder.size();i++)
        {
            ans= min(ans, abs(inorder[i] - inorder[i-1]));
        }
        
        return ans;
    }
};