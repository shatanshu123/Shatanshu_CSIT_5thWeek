class Solution {
public:
    string longestPalindrome(string s) {
        string answer = "";
        
        
        for(int i = 0; i<s.length();i++){
            
            int l = i;
            int r = i;
            // encountered odd length
            while(l >=0 and r < s.length() and s[l] == s[r]){
                if(answer.length() < r - l  + 1)answer = s.substr(l,r - l + 1);
                l--;
                r++;
                
                
            }
            
             l = i;
            r = i + 1;
            
            while(l >= 0 and r < s.length() and s[l] == s[r]){
                if(answer.length() < r - l + 1)answer = s.substr(l,r - l + 1);
               
                
                 l--;
                r++;
            }
        }
        
        return answer;
    }
};