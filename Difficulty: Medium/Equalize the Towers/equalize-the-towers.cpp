class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        
        int n = heights.size();
        
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({heights[i], cost[i]});
        }
        
        sort(v.begin(), v.end());   // sort by height
        
        long long totalWeight = 0;
        for(auto &p : v) {
            totalWeight += p.second;
        }
        
        long long currWeight = 0;
        int medianHeight = 0;
        
        for(auto &p : v) {
            currWeight += p.second;
            if(currWeight >= (totalWeight + 1) / 2) {
                medianHeight = p.first;
                break;
            }
        }
        
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += 1LL * abs(heights[i] - medianHeight) * cost[i];
        }
        
        return ans;
    }
};
