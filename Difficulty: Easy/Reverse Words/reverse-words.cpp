//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
       vector<string> temp;
       istringstream ss(str);
       string words;
       while (getline (ss, words, '.')){
           temp.push_back(words);
       }
       
       reverse(temp.begin(), temp.end());
       
       str = "";
       for(int i=0; i<temp.size(); i++){
           str += temp[i];
           if( i != temp.size()-1){
               str += ".";
           }
       }
       
       return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends