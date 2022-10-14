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
    unordered_map<int,int> mp;
public:
    
    void set(TreeNode *root)
    {
        if(!root)
            return;
        
        mp[root->val]++;
        
        set(root->left);
        set(root->right);
    }
    
    bool find(TreeNode* root, int k)
    {
        if(!root)
            return false;
        if(mp.find(k - root->val) != mp.end())
        {
            if(root->val != k/2)
                return true;
            else if(mp[root->val]>1)
                return true;
        }
            
        
        return find(root->left, k) || find(root->right, k); 
    }
    
    bool findTarget(TreeNode* root, int k) {
        set(root);
        
        return find(root, k);
        
    }
};