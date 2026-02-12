class Solution {
  public:
    int maxLength(string& s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        
        for(int i = 0;i<s.size();i++){
            if(s[i]==')'){
                st.pop();
                if(st.empty()) st.push(i);
                ans = max(i-st.top(),ans);
            }
            else{
                st.push(i);
            }
        }
        
        return ans;
    }
};