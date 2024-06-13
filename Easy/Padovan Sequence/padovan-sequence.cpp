//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
     int padovanSequence(int n)
    {
       //code here
       int mod=1e9+7;
       int arr[n];
       if(n==0 or n==1 or n==2) return 1;
       arr[0]=1;
       arr[1]=1;
       arr[2]=1;
       
        for(int i=3;i<=n;i++)
        {
            arr[i]=arr[i-2]+arr[i-3];
            arr[i]=arr[i]%mod;
        }
        return arr[n];
       
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends