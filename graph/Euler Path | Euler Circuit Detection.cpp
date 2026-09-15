class Solution {
  public:
  void dfs(int node,vector<vector<int>>& adj,vector<bool>&vis){
      vis[node] = true;
      
      for(auto nbr: adj[node]){
          if(!vis[nbr]){
              dfs(nbr,adj,vis);
          }
      }
  }
  bool isconnected(int V,vector<vector<int>>& adj){
      
      //finding non-zero degree vala vertex 
      
      int nonzero=-1;
      for(int i=0; i<V; i++){
          if(adj[i].size() != 0){
              nonzero = i;
              break;
          }
      }
      
      vector<bool>vis(V,false);
      
      // start dfs from  nonzero degree vale vertex
      dfs(nonzero,adj,vis);
      
      // check if any nonzero degree vala vertex not visited because if nor then return false
      
      for(int i=0; i<V; i++){
          if(adj[i].size() != 0 && vis[i]==false) return false;
      }
      
      return true;
  }
    int isEulerCircuit(int V, vector<vector<int>>& adj) {
        // code here
        
        // check if all non zero degree vale node connected or not
        
        if(isconnected(V,adj) == false) return 0;
        
        
        // check total number of odd degree vale node
        
        int oddDegreecnt=0;
        for(int i=0; i<V; i++){
            if(adj[i].size() & 1){
                oddDegreecnt++;
            }
        }
        
        if(oddDegreecnt == 0) return 2; // EC
        if(oddDegreecnt == 2) return 1; // EP
        return 0; // NONE
    }
};
