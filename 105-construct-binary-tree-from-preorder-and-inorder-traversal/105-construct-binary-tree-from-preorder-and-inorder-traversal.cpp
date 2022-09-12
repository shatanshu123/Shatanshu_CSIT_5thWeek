class Solution {
public:
    map<int,int> inmap;
    int pre_ind=0;
    TreeNode* rec(vector<int>& in,vector<int>& pre,int n,int in_st,int in_end)
    {
        if(in_st>in_end)
            return NULL;
        int indx=inmap[pre[pre_ind]];
        TreeNode* curr=new TreeNode(pre[pre_ind++]);
        curr->left=rec(in,pre,n,in_st,indx-1);
        curr->right=rec(in,pre,n,indx+1,in_end);
        return curr;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size(); 
        for(int i=0;i<n;i++)
            inmap[inorder[i]]=i;
         return rec(inorder,preorder,n,0,n-1);
    }
};