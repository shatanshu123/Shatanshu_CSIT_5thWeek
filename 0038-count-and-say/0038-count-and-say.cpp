//STRIVER_SDE_SHEET

class Solution {
public:
    string countAndSay(int n) {
        // base count and say
        string res = "1";
        
        while(--n){
            // temp store new count and say
            string tmp = "";
            
            for(int i = 0, start = 0; i < res.length(); i++){
                // diff next number
                if(res[i] != res[i+1]){
                    // count and say generator
                    tmp += to_string(i-start+1) + res[i];
                    start = i+1;
                }
            }
            
            // get new count and say
            res = tmp;
        }
        
        return res;
    }
};