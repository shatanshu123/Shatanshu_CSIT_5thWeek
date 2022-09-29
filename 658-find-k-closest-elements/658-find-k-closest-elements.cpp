class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low=0,high=arr.size()-k;
        while(low<high){
            int mid=low+(high-low)/2;
            if(x<=arr[mid])
                high=mid;
            else if(arr[mid+k]<=x)
                low=mid+1;
            else{
                int middist=abs(x-arr[mid]);
                int midkdist=abs(x-arr[mid+k]);
                if(middist<=midkdist)
                    high=mid;
                else
                    low=mid+1;
            }
        }
        return {arr.begin()+low,arr.begin()+low+k};
    }
};