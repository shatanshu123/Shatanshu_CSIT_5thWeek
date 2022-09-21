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
    int curr=0,val=0;
    void inorder(TreeNode* root, int k){
        if(!root)return;
        inorder(root->left,k);
        curr++;
        if(curr==k)val=root->val;
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* head=root;
        inorder(head,k);
        return val;
    }
};


   