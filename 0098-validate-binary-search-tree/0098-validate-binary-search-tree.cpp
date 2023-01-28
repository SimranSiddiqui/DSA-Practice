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
    bool validate(TreeNode* root, long mini, long maxi)
    {
        if(!root)
            return true;
        
        if(root->val <= maxi || root->val >= mini)
            return false;
        
        long value = root->val;
        long newMini = min(mini, value);
        long newMaxi = max(value, maxi);
        
        return validate(root->left, newMini, maxi) && validate(root->right, mini, newMaxi);
            
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left && !root->right))
            return true;
        
        long maxi = LONG_MIN;
        long mini = LONG_MAX;
        
        cout << maxi ;
        
        return validate(root, mini, maxi);
    }
};