class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(W + 1, vector<int>(n + 1, 0));
        for(int t = 0; t <= W; ++t)
        {
            for(int i = n - 1; i >= 0; --i)
            {
                int v1 = t >= wt[i] ? (val[i] + dp[t - wt[i]][i + 1]) : 0;
                int v2 = dp[t][i + 1];
                dp[t][i] = max(v1, v2);
            }
        }
        return dp[W][0];
    }
};