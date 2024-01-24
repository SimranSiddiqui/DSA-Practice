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
    bool check(vector<int> &pal)
    {
        int count = 0;
        for(auto it: pal)
        {
            if(it%2)
            {
                count++;
            }
        }
        
        return count < 2;
    }
    int solve(TreeNode* root, vector<int> pal)
    {
        if(root && !root->right && !root->left)
        {
            pal[root->val]++;
            return check(pal);
        }
        if(!root)
            return 0;
        
        pal[root->val]++;
        return solve(root->left, pal) + solve(root->right, pal);
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> pal(10, 0);
        
        return solve(root, pal);
    }
};