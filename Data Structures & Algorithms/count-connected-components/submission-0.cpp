class Solution {
    void dfs(vector<vector<int>> &adj, vector<int> & visited, int n){
        
        visited[n]=1;
        for(int i=0;i<adj[n].size();i++){
            if(!visited[adj[n][i]]){
                
                dfs(adj,visited,adj[n][i]);
            }
        }
    }
public:
    int countComponents(int V, vector<vector<int>>& edges) {
      vector<vector<int>>adj(V);
      int n=edges.size();
      for(int i=0;i<n;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
      }
      int cnt=0;
      vector<int> visited(V,0);
      for(int i=0;i<V;i++){
        if(!visited[i]){
          dfs( adj, visited, i);
          cnt++;
        }
      }
      return cnt;
    }
};
