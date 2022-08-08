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
class NodeValue {
    public:
        int maxSum, maxVal, minVal;
        NodeValue(int maxSum, int maxVal, int minVal){
            this->maxSum = maxSum;
            this->maxVal = maxVal;
            this->minVal = minVal;
        }
};

class Solution {
public:
    NodeValue solve(TreeNode *root, vector <int> &sums){
        if(!root) return {0, INT_MIN, INT_MAX};
        
        NodeValue valuesLeft = solve(root->left, sums);
        NodeValue valuesRight = solve(root->right, sums);
        
        if(root->val < valuesRight.minVal && root->val > valuesLeft.maxVal){
            sums.push_back(root->val + valuesRight.maxSum + valuesLeft.maxSum);
            return {root->val + valuesRight.maxSum + valuesLeft.maxSum, max(root->val, valuesRight.maxVal), min(root->val, valuesLeft.minVal)};
        }
        
        sums.push_back(max(valuesRight.maxSum, valuesLeft.maxSum));
        return {max(valuesRight.maxSum, valuesLeft.maxSum), INT_MAX, INT_MIN};
    }
        
    int maxSumBST(TreeNode* root) {
        vector <int> sums;
        sums.push_back(0);
		
        int temp = max(0, solve(root, sums).maxSum);
        
        int ans = INT_MIN;
        for(int i = 0; i < sums.size(); i++){
            ans = max(ans, sums[i]);
        }
        
        return ans;
    }
};