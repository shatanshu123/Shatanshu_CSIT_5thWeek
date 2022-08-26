class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string first=strs[0];
        string last=strs[n-1];
        string ans;
        int first_size=first.size();
        int last_size=last.size();
        int min_size=min(first_size,last_size);
        for(int i=0;i<min_size;i++){
            if(first[i]==last[i])
                ans.push_back(first[i]);
        
        else
            break;
        }
        return ans;
    }
};

