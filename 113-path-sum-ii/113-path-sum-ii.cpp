
class Solution {
public:
    vector<int>tmp;
    vector<vector<int>>res;
    void find(TreeNode *root,int sum,int target){
        tmp.push_back(root->val);
        if(sum==target && !root->left && !root->right)
            res.push_back(tmp);
        else{
            if(root->left)
                find(root->left,sum+root->left->val,target);
            if(root->right)
                find(root->right,sum+root->right->val,target);
        }
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root)
            find(root, root->val,targetSum);
        return res;
    }
};


