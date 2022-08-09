//STRIVER_SDE_SHEET

class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
  /*      priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0; i<k; i++){
            pq.push(a[i]);
        }
        for(int i=k; i<a.size(); i++){
            if(a[i]>pq.top()){
                pq.pop();
                pq.push(a[i]);
            }
        }
        return pq.top();*/
    sort(a.begin(),a.end());
        int ans=a[a.size()-k];
        return ans;
        
    }
};