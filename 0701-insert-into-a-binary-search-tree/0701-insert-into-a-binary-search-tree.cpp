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
    vector<int>v;
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        inorder(root);
        v.push_back(val);
        sort(v.begin(),v.end());
        TreeNode* ans = solve(0,v.size()-1);
        inorder(ans);
        return ans;
    }
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* solve(int left, int right){
        if(left>right) return NULL;
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = solve(left, mid-1);
        root->right = solve(mid+1, right);
        return root;
    }
};