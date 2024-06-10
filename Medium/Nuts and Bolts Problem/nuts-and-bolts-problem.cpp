//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        unordered_map<char,int> mp;
        mp['^']=1; mp['@']=2;
        mp['?']=3; mp['*']=4;
        mp['&']=5; mp['%']=6;
        mp['$']=7; mp['#']=8;
        mp['!']=9;
        
        priority_queue<pair<int,char>> pq;
        for(int i=0; i<n; i++){
            pq.push({mp[nuts[i]],nuts[i]});
        }
        for(int i=0; i<n; i++){
            nuts[i]=bolts[i]=pq.top().second;
            pq.pop();
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends