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
    int rec(TreeNode* root,int& res ){
        if(root==nullptr) return 0;
		// maximum value from left
        int l = rec(root->left,res);
		//maximum value from right
        int r = rec(root->right,res);
        
		//check if path can go through this node ,if yes upadte the result value
        res = max(res,root->val+l+r);
        
		// return the maximum non-negative path value
        return max({l+root->val,r+root->val,0});
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int x = rec(root,res);
        return res;
    }
};