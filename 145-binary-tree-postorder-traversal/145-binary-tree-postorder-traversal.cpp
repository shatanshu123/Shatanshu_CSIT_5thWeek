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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)
            return ans;
        Treehelper(root,ans);
        return ans;
    }
    void Treehelper(TreeNode *root, vector<int>&ans){
        if(!root)
            return;
        Treehelper(root->left,ans);
        Treehelper(root->right,ans);
        ans.push_back(root->val);
    }
};