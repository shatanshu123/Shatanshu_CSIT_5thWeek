class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int n=chars.size();
        int ansind=0;
        while(i<n)
        {
            int j=i+1;
            while(j<n&&chars[i]==chars[j])
                j++;
            chars[ansind++]=chars[i];
            int count=j-i;
            if(count>1)
            {
                string cnt=to_string(count);
                for(char c:cnt)
                {
                    chars[ansind++]=c;
                }
            }
            i=j;
        }
        return ansind;
    }
};