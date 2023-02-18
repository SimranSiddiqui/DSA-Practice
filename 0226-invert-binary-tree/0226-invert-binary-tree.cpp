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
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        
        inorder(root->left);
        inorder(root->right);
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {
        inorder(root);
        return root;
    }
};