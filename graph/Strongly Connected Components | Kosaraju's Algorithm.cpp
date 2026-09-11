class Solution {
  public:
  void sccdfs(int node,vector<bool>&vis,unordered_map<int,vector<int>>&revadj){
      vis[node] =true;
      
      for(auto nbr: revadj[node]){
          if(!vis[nbr]){
              sccdfs(nbr,vis,revadj);
          }
      }
  }
  void topodfs(int node,vector<bool>&vis,stack<int>&st,unordered_map<int ,vector<int>>&adj){
      vis[node] = true;
      
      for(auto nbr: adj[node]){
          if(!vis[nbr]){
              topodfs(nbr,vis,st,adj);
          }
      }
      
      st.push(node);
    }
    int countSCC(int V, vector<vector<int>> &edges) {
        // code here
        // step - 1  store element in stack using topo sort
        
        unordered_map<int ,vector<int>>adj;
        for(auto e: edges){
            int u= e[0];
            int v=e[1];
            
            adj[u].push_back(v);
        }
        stack<int>st;
        vector<bool>vis(V,false);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                topodfs(i,vis,st,adj);
            }
        }
        
        //  step - 2 reverse the graph
        
        unordered_map<int,vector<int>>revadj;
        for(auto e: edges){
            int u= e[0];
            int v=e[1];
            
            revadj[v].push_back(u);
        }
        
        
        // step - 3  , now count the number of strongly connected components
        
        vis= vector<bool>(V,false);
        int scc=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                sccdfs(node,vis,revadj);
                scc++;
            }
        }
        
        return scc;
    }
};
