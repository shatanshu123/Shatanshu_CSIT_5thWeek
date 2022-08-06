//STRIVER_SDE_SHEET
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        map<int, map<int, multiset<int> > > nodes;  // x: (y: {elements on x})
        queue<pair<TreeNode*, pair<int, int> > > q; // {node, {x, y}}
        q.push({root, {0, 0}});
        
       while(!q.empty()){
            auto temp = q.front();
            q.pop();
            auto firstNode = temp.first;
            auto x = temp.second.first;
            auto y = temp.second.second;
            
            nodes[x][y].insert(firstNode->val);
            if(firstNode->left) q.push({firstNode->left, {x-1, y+1}});
            if(firstNode->right) q.push({firstNode->right, {x+1, y+1}});
        }
        vector<vector<int> > ans;

        for(auto i: nodes){
            vector<int> p;
            for(auto j: i.second){
                for(auto k: j.second){
                    p.push_back(k);
                }
            }
        ans.push_back(p);
        }
        return ans;
    }
};