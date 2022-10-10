class Solution {
public:
    string breakPalindrome(string s) {
        int n=s.size();
        if(n==1){
            return "";
        }
        char ch='a';
        int idx=-1;
        for(int i=0;i<n/2;i++){
            if(ch<s[i]){
                s[i]='a';
                return s;
            }
        }
        s[n-1]='b';
        return s;
    }
};