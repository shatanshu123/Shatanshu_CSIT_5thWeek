//STRIVER_SDE_SHEET
class Solution {
public:
        
    int romanToInt(string s) {
        const string str = "IVXLCDM";
        const int idx[] = {1, 5, 10, 50, 100, 500, 1000};
        
        int i = s.length() - 1;
        int r = 0;
        int last = 0;
        while (i >= 0) {
            int n1;
            
            size_t p = str.find(s[i]);
            n1 = idx[p];
            
            if (n1 >= last) {
                r += n1;
            } else  {
                r -= n1;
            }
            last = n1;
            
            i--; 
        }
        
        return r;
    }
};