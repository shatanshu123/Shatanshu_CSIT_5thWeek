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
    
    int curr = 0;
    int val = 0;
    void inorder(TreeNode* head, int k)
    {
        if(!head)
            return;
        
        inorder(head->left, k);
        
        curr++;
        
        if(curr==k)
        {
            val = head->val;
        }
        
        inorder(head->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        TreeNode* head = root;
        
        inorder(head, k);
        return val;
        
    }
};