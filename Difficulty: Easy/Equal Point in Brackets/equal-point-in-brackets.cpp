class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int openBracket = 0, closeBracket = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ')') {
                closeBracket++;
            }
        }
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(')
                openBracket++;
            
            if(s[i] == ')')
                closeBracket--;
                
            if(openBracket == closeBracket) {
                return i+1;
            }
        }
        
        return 0;
    }
};