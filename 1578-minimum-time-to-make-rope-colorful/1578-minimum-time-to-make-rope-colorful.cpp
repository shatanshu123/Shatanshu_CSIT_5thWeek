class Solution {
public:
     int minCost(string colors, vector<int>& Time) {
        int n = colors.size();
        int m = Time.size();
        int sum = 0;
       for(int i = 1; i<n; i++){
           if(colors[i] == colors[i-1]){
               for(int j = i-1; j<i; j++){
                   sum += min(Time[j], Time[i]);
                   if(Time[i]<Time[j]) Time[i] = Time[j];
               }
           }
       }
        return sum;
     }
};