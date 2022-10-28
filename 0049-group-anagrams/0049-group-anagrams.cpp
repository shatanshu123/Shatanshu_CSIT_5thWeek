class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>ans;
        vector<string>v=strs;
        int n=strs.size();
        
        map<string,vector<int>>m;
        
        for(int i=0;i<n;i++){
            
            sort(v[i].begin(),v[i].end());
            m[v[i]].push_back(i);
            
        }
        
        for(auto x:m){
            vector<string>s;
            for(int y:x.second){
                s.push_back(strs[y]);
            }
            ans.push_back(s);
        }
        
        return ans;
    }
};