class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        //set to store unique valid mails
        set<string>ans;
        
        for(auto email:emails){
            string s;
            for(auto i:email){
                if(i=='.')
                    i++;
                else if(i=='+' or i=='@'){
                    //find pos of '@';
                    int posAt = email.find('@');
                    s+=email.substr(posAt,email.length()-posAt);
                    break;
                }else
                    s+=i;
    
            }
            
            ans.insert(s);
        }
                
        return ans.size();
    }
};