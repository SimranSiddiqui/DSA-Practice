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
     bool solve(TreeNode* root, long maxi, long mini){
        // cout<<endl;
        // cout<<"maxi : "<<maxi<<" mini : "<<mini<<" ";
        if(!root){
            // cout<<" 1 ";
            return true;
        }
        if(root->val >= maxi || root->val <= mini){
            // cout<<" 2 ";
            return false;
        }
        if(root->left) if(root->left->val >= root->val){
            // cout<<" 3 ";
            return false;
        }
        if(root->right) if(root->right->val <= root->val){
            // cout<<" 4 ";
            return false;
        }
        // cout<<" 5 ";
        return solve(root->left, root->val, mini) && solve(root->right, maxi, root->val);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return solve(root->left, root->val, LONG_MIN) && solve(root->right, LONG_MAX, root->val);
    }
};