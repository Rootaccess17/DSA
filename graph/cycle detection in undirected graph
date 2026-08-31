class Solution {
  public:
  bool dfs(int node, int par,unordered_map<int,vector<int>> &adj,vector<bool> &vis){
      vis[node]=true;
      
      for(auto child: adj[node]){
          if(child==par) continue;
          
          if(vis[child] || dfs(child,node,adj,vis)) return true;
          
      }
      
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        unordered_map<int,vector<int>>adj;
        for(auto e: edges){
            int u= e[0];
            int v= e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>vis(V,false);
        
        for(int i=0; i<V; i++){
            if(!vis[i] && dfs(i,-1,adj,vis)) return true;
        }
        return false;
    }
};
