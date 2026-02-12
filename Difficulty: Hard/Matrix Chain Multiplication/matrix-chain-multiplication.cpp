class Solution {
  public:
    int f(int i , int j , vector<int> & arr ,  vector<vector<int>> &dp) {
        if(i == j || i+1 == j) return 0 ;
        if(dp[i][j] != -1) return dp[i][j] ;
        int ans = INT_MAX ;
        for(int k = i+1 ; k< j ; k++) {
            ans = min(ans , f(i , k , arr , dp) + f(k , j , arr, dp) + arr[i] * arr[j] * arr[k]) ;
        }
        return dp[i][j] =  ans ;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size() ;
        vector<vector<int>> dp(205 , vector<int>(205 , -1)) ;
        return f(0 , n-1 , arr , dp) ;
    }
};