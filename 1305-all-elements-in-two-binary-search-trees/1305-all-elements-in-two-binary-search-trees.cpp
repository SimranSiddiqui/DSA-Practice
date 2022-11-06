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
    
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if(root == NULL)
            return;
        ans.push_back(root->val);
        inorder(root->left, ans);
        inorder(root->right, ans);
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        
        inorder(root1,ans);
        inorder(root2,ans);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};