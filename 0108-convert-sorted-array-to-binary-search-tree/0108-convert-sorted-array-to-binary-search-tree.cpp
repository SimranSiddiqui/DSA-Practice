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
    void solve(TreeNode* &root, vector<int> &nums, int l, int r)
    {
        if(l <= r)
        {
            int mid = (l+r)/2;
            root = new TreeNode();
            root->val = nums[mid];
            
            solve(root->left, nums, l, mid-1);
            solve(root->right, nums, mid+1, r);
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = NULL;
        
        solve(root, nums, 0, n-1);
        return root;
    }
};