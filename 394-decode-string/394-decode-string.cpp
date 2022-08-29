class Solution {
public:
    stack<int> S;
    stack<string> SS;
    vector<int> V;
    
    bool isD(char c) {
        return c >= '0' && c <= '9';
    }
    
    string repeat(int k, string str) {
        string res = "";
        while (k--) {
            res += str;
        }
        return res;
    }
    
    string decodeString(string s) {
        int i = 0;
        int len = s.length();
        string tmp = "";
        string rs = "";
        while (i < len) {
            while (i < len && !isD(s[i])) {
                rs += s[i];
                i++;
            }
            tmp = "";
            while (i < len && isD(s[i])) {
                tmp += s[i];
                i++;
            }
            if (tmp.length() > 0)
                V.push_back(stoi(tmp));
        }
        int bidx = 0;
        int cs;
        string css;
        for (char c : rs) {
            if (c == '[') {
                S.push(bidx);
                SS.push("");
                bidx++;
            }
            else if (c == ']') {              
                cs = S.top();
                css = SS.top();
                tmp = repeat(V[cs], css);
                SS.pop();
                S.pop();
                if (!SS.empty()) {
                    css = SS.top();
                    tmp = css + tmp;
                    SS.pop();
                    SS.push(tmp);
                }
                else {
                    SS.push(tmp);
                }
            }
            else {
                if (SS.empty()) {
                    tmp = "";
                    tmp += c;
                    SS.push(tmp);
                }
                else {
                    tmp = SS.top();
                    SS.pop();
                    tmp += c;
                    SS.push(tmp);
                }
            }
        }
        string res = "";
        while (!SS.empty()) {
            css = SS.top();
            res = css + res;
            SS.pop();
        }
        return res;
    }
};