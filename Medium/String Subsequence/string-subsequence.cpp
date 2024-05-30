//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int t[501][501];
    int mod=1e9+7;
  public:
  int helper(string s1,string s2 ,int n,int m){
      if(m==0)return 1;
      if(n==0)return 0;
      if(t[n][m]!=-1)return t[n][m]%mod;
      if(s1[n-1]==s2[m-1]){
          t[n][m]=helper(s1,s2,n-1,m-1)%mod+helper(s1,s2,n-1,m)%mod;
      }else{
          t[n][m]=helper(s1,s2,n-1,m)%mod;
      }
       return t[n][m]%mod;
  }
    int countWays(string s1, string s2) {
        memset(t,-1,sizeof(t));
        int n=s1.size();
        int m=s2.size();
        return helper(s1,s2,n,m);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends