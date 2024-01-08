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

    void inorder(TreeNode* root, int low, int high, int *sum)
    {
        if(!root)
        return;

        if(root->val>=low && root->val<=high)
        *sum += root->val;

        inorder(root->left, low, high, sum);
        inorder(root->right, low, high, sum);
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum =0;
        inorder(root, low, high, &sum);
        return sum;
    }
};