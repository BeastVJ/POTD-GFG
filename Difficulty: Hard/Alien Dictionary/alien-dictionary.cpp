class Solution {
public:
    string findOrder(vector<string> &words) {
        int k = 26;
        vector<int> adj[k];
        vector<int> indegree(k, 0);
        vector<bool> present(k, false);

        // Mark present characters
        for (auto &w : words) {
            for (char c : w)
                present[c - 'a'] = true;
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.length(), s2.length());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    indegree[s2[j] - 'a']++;
                    found = true;
                    break;
                }
            }

            //  Prefix invalid case
            if (!found && s1.length() > s2.length())
                return "";
        }

        // Kahn's Algorithm
        queue<int> q;
        int presentCount = 0;

        for (int i = 0; i < k; i++) {
            if (present[i]) {
                presentCount++;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }

        string ans = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(char(node + 'a'));

            for (int it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        // Cycle check
        if (ans.length() != presentCount)
            return "";

        return ans;
    }
};

