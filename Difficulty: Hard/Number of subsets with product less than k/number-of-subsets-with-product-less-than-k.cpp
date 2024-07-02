//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int solve(int n, int k, int arr[]){
        vector<int> curr(k+1, 1);
        vector<int> next(k+1, 1);

        for(int i = n-1; i >= 0; i--){
            for(int z = 1; z <= k; z++){
                int take = 0;
                if(arr[i] <= z){
                    take = next[z/arr[i]];
                }
                
                int skip = next[z];
                
                curr[z] = skip+take;
            }
            next = curr;
        }
        return next[k];
    }
  
    int numOfSubsets(int arr[], int n, int k) {
        return solve(n, k, arr)-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends