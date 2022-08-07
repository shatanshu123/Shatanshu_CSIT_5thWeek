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
    TreeNode* construct(vector<int> &preorder, int &idx, int mn, int mx, int size)
    {
        if (idx >= size) // All the nodes have been created.
            return NULL;
        TreeNode* n = NULL;
        if (preorder[idx] > mn && preorder[idx] < mx) 
        {
            int key = preorder[idx++];
            n = new TreeNode(key);
            n->left = construct(preorder, idx, mn, key, size);
            n->right = construct(preorder, idx, key, mx, size);
        }
        return n;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        int size = preorder.size();
        return construct(preorder, idx, INT_MIN, INT_MAX, size);
    }
};
