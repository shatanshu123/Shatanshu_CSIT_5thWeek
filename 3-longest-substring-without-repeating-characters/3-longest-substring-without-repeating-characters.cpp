class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastocc(128, -1);
        int maxLen = 0, start = -1;
        int l = s.length();
        for (int i = 0; i != l; i++) {
            if (lastocc[s[i]] > start)
                start = lastocc[s[i]];
            lastocc[s[i]] = i;
            if ((i-start) > maxLen) 
                maxLen = i-start;
        }
        return maxLen;
    }
};
