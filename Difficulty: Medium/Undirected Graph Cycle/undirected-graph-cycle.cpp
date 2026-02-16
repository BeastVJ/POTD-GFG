class Solution {
    private:
   bool getAns(int  x, vector<int> &vis, vector<int> adj[], int V){
       queue<int> q;
       vector<int> parent(V+1);
       q.push(x);
       parent[x]=-1;
       vis[x]=1;
       while(!q.empty()){
           int node= q.front();
           q.pop();
           for(auto i: adj[node]){
               if(vis[i] and parent[node]!=i)return true;
               if(vis[i])continue;
               q.push(i);
               vis[i]=1;
               parent[i]=node;
           }
       }
       return false;
   }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V+1];
        for(int i=0; i<edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V+1, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(getAns(i, vis, adj, V))return true;
            }
        }
        return false;
    }
};