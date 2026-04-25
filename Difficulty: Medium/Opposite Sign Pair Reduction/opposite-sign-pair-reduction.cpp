class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        stack<int> st;

        for(int x : arr) {
            while(!st.empty() && st.top() * x < 0) { // opposite signs
                int top = st.top();

                if(abs(top) > abs(x)) {
                    // current element destroyed
                    x = top;
                    st.pop();
                }
                else if(abs(top) < abs(x)) {
                    // stack top destroyed
                    st.pop();
                }
                else {
                    // equal absolute values → both destroyed
                    st.pop();
                    x = 0;
                    break;
                }
            }

            if(x != 0) {
                st.push(x);
            }
        }

        // convert stack → vector
        vector<int> result(st.size());
        for(int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};