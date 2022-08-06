class Solution {
public:
    void dfs(vector<vector<int>> &rooms, vector<int> &visited, int node){
        visited[node] = 1;
        
        for(auto x: rooms[node]){
            if(!visited[x]) dfs(rooms, visited, x);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        dfs(rooms, visited, 0);
        
        for(int i=1;i<n;i++){
            if(visited[i] == 0) return false;
        }

        return true;
    }
};
