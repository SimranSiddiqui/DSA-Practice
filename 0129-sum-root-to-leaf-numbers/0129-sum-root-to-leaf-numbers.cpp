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
    
    void countSum(TreeNode *root, int sum, int &ans)
    {
        if(!root)
            return;
        if(!root->right && !root->left)
        {
           ans += sum*10+root->val;
            return;
        }
        
        countSum(root->left, sum*10+root->val, ans);
        countSum(root->right, sum*10+root->val, ans);
    }
    
public:
    int sumNumbers(TreeNode* root) {
        int sum =0, ans =0;
        countSum(root, sum, ans);
        return ans;
    }
};