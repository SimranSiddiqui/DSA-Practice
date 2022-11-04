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
    
    int depth(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        return max(1+depth(root->left) , 1+depth(root->right));
    }
    
    void deepSum(TreeNode *root, int count, int *sum, int maxDepth)
    {
        if(root->right == NULL && root->left == NULL && count == maxDepth)
        {
            *sum += root->val;
            return;
        }
         if(root->right == NULL && root->left == NULL)
        {
            return;
        }
        
        if(root->right)
        deepSum(root->right, count+1, sum, maxDepth);
        if(root->left)
        deepSum(root->left, count+1, sum, maxDepth); 
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = depth(root);
        int count = 1;
        int sum =0;
        
        deepSum(root, count, &sum, maxDepth);
        
        return sum;
    }
};