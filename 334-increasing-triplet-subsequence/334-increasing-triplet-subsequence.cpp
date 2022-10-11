class Solution {
public:

bool increasingTriplet(vector<int> &nums) {
    
    int n = nums.size();
    int a = INT_MIN;
    int b = INT_MIN;
    int c = INT_MIN;
    
    for(int i=n-1; i>=0; i--){
        
        if(nums[i] >= c){
            c = nums[i];
        }
        else if(nums[i] >= b){
            b = nums[i];
        }
        else{
            
            return true;
        }
        
    }
    
    
    return false;
    
}
};