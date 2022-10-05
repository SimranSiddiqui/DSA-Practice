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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL)
            return root;
        
        if(depth == 1)
        {
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            root = newNode;
            return root;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 1;
        
        while(!q.empty() && level<depth )
        {
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                TreeNode *node = q.front();
                q.pop();
               
                    if(level == depth-1)
                    {
                        TreeNode *newNodeL = new TreeNode(val);
                        if(!node->left)
                        {
                            newNodeL->left = NULL;
                            node->left = newNodeL;
                        }
                        else
                        {
                           newNodeL->left = node->left;
                           node->left = newNodeL; 
                        }
                         
                         TreeNode *newNodeR = new TreeNode(val);
                        if(!node->right)
                        {
                           newNodeR->right = NULL;
                            node->right = newNodeR; 
                        }
                        else
                        {
                           newNodeR->right = node->right;
                           node->right = newNodeR;  
                        }
                        
                    }
                    else
                    {
                     if(node->left)  
                    {
                        q.push(node->left);
                    }
                    if(node->right)
                    {
                        q.push(node->right);
                    }   
                    }
       
            }
                
                level++;
            }
        
        return root;
    }
        
};