class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string ans = "";
        string an = " ";
        for(int i = 0; i< s.length(); i++){
            if(s[i]!= ' '){
                ans += s[i];
                // i++;
            }
        }
        return ans;
    }
};