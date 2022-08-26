class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='[')
                st.push(ch);
            else{
                if(st.empty()) return false;
                if(st.top()=='(' && s[i]!=')' )return false;
                if(st.top()=='{' && s[i]!='}')return false;
                if(st.top()=='[' && s[i]!=']') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};