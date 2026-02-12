class Solution {
  public:
    void FindArticulationPoint(int node, int &_time, int V, vector<int> adj[], vector<int> &parent, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<bool> &points)
    {
        visited[node] = true;
        disc[node] = low[node] = _time;
        _time++;
        int cnt = 0;
        for(int i = 0;i<adj[node].size();i++)
        {
            int neigh = adj[node][i];
            
            // skipping the case of parent
            if(neigh == parent[node]){
                continue;
            }
            
            // neighbour is visited (Back edge case)
            if(visited[neigh]){
                low[node] = min(low[node], disc[neigh]);
            }
            else{
                parent[neigh] = node;
                FindArticulationPoint(neigh, _time, V, adj, parent, disc, low, visited, points);
                low[node] = min(low[neigh], low[node]);
                
                if(parent[node]!=-1 and low[neigh]>=disc[node]){
                    points[node] = true;
                }
                
                // only unvisited nodes are counted as child
                cnt++;
            }
        }
        if(parent[node] == -1 and cnt>=2){
            points[node] = true;
        }
    }
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> parent(V, -1);
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> points(V, false);
        vector<bool> visited(V, false);
        
        int _time = 0;
        for(int node = 0;node<V;node++){
            if(!visited[node]){
                FindArticulationPoint(node, _time, V, adj, parent, disc, low, visited, points);
            }
        }
        
        vector<int> sol;
        for(int i = 0;i<V;i++)if(points[i] == true)sol.push_back(i);
        
        if(sol.empty())return vector<int>{-1};
        return sol;
    }
};