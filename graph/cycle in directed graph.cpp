class Solution {
  public:
  bool cycle(int node,unordered_map<int,vector<int>> &adj,vector<bool> &vis,vector<bool>&recursion){
      vis[node]=true;
      recursion[node]=true;
      
      for(auto child: adj[node]){
          if(vis[child] && recursion[child]) return true;
          
          if(!vis[child] && cycle(child,adj,vis,recursion)) return true;
          
      }
      recursion[node] = false;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        
        for(auto e: edges){
            int u= e[0];
            int v= e[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool>vis(V,false);
        vector<bool>recursion(V,false);
        
        for(int i=0; i<V; i++){
            if(!vis[i] && cycle(i,adj,vis,recursion)) return true;
        }
        
        return false;
    }
};
