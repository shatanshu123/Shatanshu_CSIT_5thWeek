class Solution {
public:
    int firstUniqChar(string s) {
        vector <int> alpha(26,0);
        int n=s.size();
        for(int i=0;s[i]!='\0';++i)
            alpha[s[i]-'a']+=1;
        for(int i=0;s[i]!='\0';++i)
            if(alpha[s[i]-'a']==1)
                return i;
        return -1;
    }
};