class Solution {
public:
    
    bool static comp(vector<int>& p1, vector<int>& p2) {
        
        return (p1[0]*p1[0] + p1[1]*p1[1]) < (p2[0]*p2[0] + p2[1]*p2[1]);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        sort(points.begin(), points.end(), comp);
        vector<vector<int>> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(points[i]);
        }
        return ans;
    }
};