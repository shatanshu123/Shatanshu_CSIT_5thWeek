class Solution {
    void storeParents(unordered_map<TreeNode*, TreeNode*> &mp, TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* par = q.front();
            q.pop();
            
            if(par->left) {
                q.push(par->left);
                mp[par->left] = par;
            }
            
            if(par->right) {
                q.push(par->right);
                mp[par->right] = par;
            }
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root)
            return {};
    
        unordered_map<TreeNode *, TreeNode *> parents;
        storeParents(parents, root);
    
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        visited[target] = true;
        q.push(target);
    
        while (!q.empty()) {
            int size = q.size();
            if (k-- == 0)
                break;
    
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
    
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
    
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
    
                if (parents[node] && !visited[parents[node]]) {
                    q.push(parents[node]);
                    visited[parents[node]] = true;
                }
            }
        }
        
            vector<int> results;
            while (!q.empty()) {
                results.push_back(q.front()->val);
                q.pop();
            }
        
            return results;
    }
};