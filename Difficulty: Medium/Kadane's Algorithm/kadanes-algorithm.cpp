class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int maxi = INT_MIN;
        int n = arr.size();
        if(n ==1 ) return arr[0];
        int currmax = 0;
        for(int i = 0; i< n; i++){
            // for(int j = i; j< n; j++){
                currmax += arr[i];
                // cout<<currmax<<" ";
                maxi = max(maxi, currmax);
                
                if(currmax < 0){
                    currmax = 0;
                }
            // }
            // currmax = 0;
        }
        return maxi;
    }
};