class Solution {
  public:
    int countSubset(vector<int> &arr, int k) {
        int n = arr.size();

        // 🔥 CRITICAL SHORT-CIRCUIT
        bool allNegative = true;
        for (int x : arr) {
            if (x >= 0) {
                allNegative = false;
                break;
            }
        }

        // If all elements are negative and k >= 0 → no valid subset
        if (allNegative) {
            return 0;
        }

        // Standard DP for non-negative elements
        vector<int> dp(k + 1, 0);
        dp[0] = 1;

        for (int x : arr) {
            if (x < 0 || x > k) continue; // ignore negatives safely

            for (int j = k; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }

        return dp[k];
    }
};
