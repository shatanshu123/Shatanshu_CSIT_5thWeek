class Solution {
public:
    // recursive function
    int ways(int i, string s, vector<int> &dp){
        // base case
        if(s[i] == '0'){
            return 0;
        }
        if(i== s.size()){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int x = ways(i+1,s,dp);
        int y = 0;
        if(i < s.size()-1 && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6' )){
            y+= ways(i+2,s,dp);
        }
        return dp[i] = x + y;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1 , -1);
        int ans = ways(0,s , dp);
        return ans;
    }
};