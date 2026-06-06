class Solution {
  public:
 
    int numOfWays(int n, int m) {
        auto f = [&](int i, int j)->bool{
          return i>=0 && j>=0 && i<n && j<m;  
        };
        vector<int> d = {-2,-1,1,2};
        int ans = 0;
        int total = n*m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int cnt = 0;
                cnt += f(i-2,j-1);
                cnt += f(i-2,j+1);
                cnt += f(i+2,j-1);
                cnt += f(i+2,j+1);
                cnt += f(i-1,j-2);
                cnt += f(i-1,j+2);
                cnt += f(i+1,j-2);
                cnt += f(i+1,j+2);
                ans += (total - cnt - 1);
            }
        }
        
        return ans;
    }
};