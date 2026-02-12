class Solution {
    void dfs(unordered_map<char, vector<char>> &adj, vector<int> &vis, char node){
        vis[node-'a']=1;
        for(char i: adj[node]){
            if(!vis[i-'a'])
            dfs(adj, vis, i);
        }
    }
  public:
    int isCircle(vector<string> &arr) {
        // code here
        ///find the indegtree and outdegree of thie n
       unordered_map<char, vector<char>> adj;
        vector<int> indeg(26, 0);
        vector<int> outdeg(26, 0);
        for(int i=0; i<arr.size(); i++){
            string str= arr[i];
            char u1= str[0];
            char v1= str[str.size()-1];
            int u= str[0]-'a';
            int v= str[str.size()-1]-'a';
            indeg[v]++;
            outdeg[u]++;
            adj[u1].push_back(v1);
        }
        for(int i=0; i<26; i++){
            if(indeg[i]!=outdeg[i])
            return 0;
        }
        vector<int> vis(26, 0);
        // and they must be connected
        dfs(adj, vis, arr[0][0]);
        for(int i=0; i<26; i++){
            if(indeg[i] and !vis[i])
            return 0;
        }
        return 1;
    }
};