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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode*current = root;
        while(current)
       {
        if(!current->left)
        {
            ans.push_back(current->val);
            current = current->right;
        }
        else
        {
            TreeNode*prev = current->left;
            while(prev->right && prev->right !=current)
            {
                prev = prev->right;
            }
            if(!prev->right)
            {
                prev->right = current;
                current = current->left;
            }
            else{
                prev->right = NULL;
                ans.push_back(current->val);
                current = current->right;
            }
        }
    }
    return ans;


    }
};