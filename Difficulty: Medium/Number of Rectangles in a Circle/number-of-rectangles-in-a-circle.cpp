//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int rectanglesInCircle(int r) {
        int count = 0;
        int radiusSquared = r * r;
        
        // We check for each possible rectangle dimensions (width, height)
        for (int width = 1; width <= 2 * r; ++width) {
            for (int height = 1; height <= 2 * r; ++height) {
                // Check the distance from the center (0,0) to each corner
                // We only need to check one corner (width/2, height/2) because of symmetry
                double halfWidth = width / 2.0;
                double halfHeight = height / 2.0;
                if (halfWidth * halfWidth + halfHeight * halfHeight <= radiusSquared) {
                    count++;
                }
            }
        }
        return count;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends