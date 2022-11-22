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
    
    int height(TreeNode * root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int l = height(root->left);
        int r = height(root->right);
        
        return max(l,r) +1;
    }
    
    
    void maxDiameter(TreeNode * root, int &maxi)
    {
        if(root == NULL)
            return;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        maxi = max(maxi, lh+rh);
        
        maxDiameter(root->left, maxi);
        maxDiameter(root->right, maxi);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxi = INT_MIN;
        maxDiameter(root, maxi);
        
        return maxi;
    }
};