//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> getPrimes(int n) {
        vector<bool> isP(n+1,true);
        isP[0]=isP[1]=false;
        for(int i=2;i*i<=n;i++){
            if(isP[i]){
                for(int j=i*i;j<=n;j+=i) isP[j]=false;
            }
        }
        vector<int> p;
        for(int i=2;i<=n;i++) if(isP[i]) p.push_back(i);
        int i=0,j=p.size()-1;
        if(n&1){
            if(isP[n-2]) return {2,n-2};
            else return {-1,-1};
        }
        while(i<=j){
            if(p[i]+p[j]==n) return {p[i],p[j]};
            if(p[i]+p[j]<n)i++;
            else j--;
        }
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends