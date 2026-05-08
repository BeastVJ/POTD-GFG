class Solution {
public:

    int minRemoval = INT_MAX;

    set<string> st;

    void solve(string &s,
               int i,
               int open,
               int close,
               int removed,
               string &temp)
    {
        // invalid prefix
        if(close > open)
            return;

        // base condition
        if(i == s.size())
        {
            if(open == close)
            {
                // better answer found
                if(removed < minRemoval)
                {
                    minRemoval = removed;

                    st.clear();

                    st.insert(temp);
                }

                // same minimum removals
                else if(removed == minRemoval)
                {
                    st.insert(temp);
                }
            }

            return;
        }

        char ch = s[i];

        // =========================
        // TAKE
        // =========================

        temp.push_back(ch);

        if(ch == '(')
        {
            solve(s,
                  i + 1,
                  open + 1,
                  close,
                  removed,
                  temp);
        }

        else if(ch == ')')
        {
            solve(s,
                  i + 1,
                  open,
                  close + 1,
                  removed,
                  temp);
        }

        else
        {
            solve(s,
                  i + 1,
                  open,
                  close,
                  removed,
                  temp);
        }

        temp.pop_back();

        // =========================
        // NOT TAKE
        // =========================

        solve(s,
              i + 1,
              open,
              close,
              removed + 1,
              temp);
    }

    vector<string> validParenthesis(string &s)
    {
        string temp = "";

        solve(s, 0, 0, 0, 0, temp);

        return vector<string>(st.begin(), st.end());
    }
};