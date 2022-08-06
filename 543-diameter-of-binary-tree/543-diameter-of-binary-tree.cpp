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
//STRIVER_SDE_SHEET
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int a=height(root);
        return res-1;
    }
    int res=0;
    int height (TreeNode *r){
        if(r==NULL)
            return 0;
        int lh=height(r->left);
        int rh=height(r->right);
        res=max(res,1+lh+rh);
        return max(lh,rh)+1;
    }
};
