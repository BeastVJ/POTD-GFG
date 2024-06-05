//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int sumA=0,sumB=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sumA+=a[i];
            mp[a[i]]++;
        }
        for(int j=0;j<m;j++){
            sumB+=b[j];
        }
        if(sumA==sumB) return 1;
        if((sumA+sumB)&1) return -1;
        int diff=max(sumA,sumB)-(sumA+sumB)/2;
        for(int j=0;j<m;j++){
            if(sumA>sumB){
                if(mp.find(diff+b[j])!=mp.end()) return 1;
            }
            else if(sumA<sumB){
                if(mp.find(b[j]-diff)!=mp.end()) return 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends