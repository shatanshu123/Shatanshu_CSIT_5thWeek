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
    TreeNode* del(TreeNode* root, int key)
    {
        if(root == NULL)
            return NULL;
        
        if(root->val == key)
        {
            //It is a leaf Node
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
                
            //If only left node is present.
            if(root->left && root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            
            //If only right node is present.
            if(root->left == NULL && root->right)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            
            //If both left and right nodes are present.
            if(root->left && root->right)
            {
                //Find value of root->right's extreme left.
                TreeNode* cur = root->right;
                while(cur->left != NULL)
                {
                    cur = cur->left;
                }
                int newval = cur->val;
                root->val = newval;
                
                root->right = del(root->right, newval);
                return root;
            }
        }
        
        if(root->val > key)
             root->left = del(root->left, key);
        else if(root->val < key)
             root->right = del(root->right, key);
        
        return root;
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        return del(root, key);
    }
};