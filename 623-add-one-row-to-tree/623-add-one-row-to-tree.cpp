class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth,bool lft=true) {
        if(root==NULL and depth!=1){
            return NULL;
        }
        if(depth==1){
            TreeNode*nd=new TreeNode(val);
            if(lft)
                nd->left=root;
            else
                nd->right=root;
            return nd;
        }
        root->left=addOneRow(root->left,val,depth-1,true);
        root->right=addOneRow(root->right,val,depth-1,false);
        return root;
    }
};