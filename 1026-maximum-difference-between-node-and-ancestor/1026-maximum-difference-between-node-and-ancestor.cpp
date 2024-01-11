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
    int solve(int mini, int maxi, TreeNode* root, int ans)
    {
        if(!root)
            return ans;
        
        int diff = max(abs(mini - root->val), abs(maxi - root->val));
        ans = max(ans, diff);
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        
        return max(solve(mini, maxi, root->left, ans), solve(mini, maxi, root->right, ans));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int mini = root->val;
        int maxi = root->val;
        int ans = INT_MIN;
        
        return solve(mini, maxi, root, ans);
    }
};