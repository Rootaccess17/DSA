class Solution {
  public:
  bool dfs(int curnode,vector<int>&color,unordered_map<int,vector<int>>&adj, int curcolor){
      color[curnode] = curcolor;
      
      for(auto nbr: adj[curnode]){
          if(color[nbr] == color[curnode]) return false;
          
          if(color[nbr]==-1){
              
              if(dfs(nbr,color,adj,1-curcolor)==false) return false;
          }
      }
      
      return true;
  }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        unordered_map<int,vector<int>>adj;
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // hrere color vector also work as vis vector
        
        vector<int>color(V,-1);
        
        for(int i=0; i<V; i++){
            if(color[i]==-1){
                if(dfs(i,color,adj,1)== false){ // 1->red , 0->green color
                    return false;
                }
            }
        }
        return true;
    }
};
