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
     void traversal(TreeNode * root, vector<int> &v)
     {
        if(root == NULL)
        return;
        if(!root->left && !root->right)
        v.push_back(root->val);

        traversal(root->left, v);
        traversal(root->right, v);
     }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
         traversal(root1, v1);
         traversal(root2, v2);
         
         if(v1.size() != v2.size())
         return false;

         for(int i=0;i<v1.size();i++)
         {
             cout << v2[i];
             if(v1[i] != v2[i])
             return false;
         }

         return true;
    }
};