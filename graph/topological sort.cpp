class Solution {
  public:
  void dfs(int node,vector<int>&vis,stack<int>&st,unordered_map<int,vector<int>>&adj){
      vis[node]=true;
      
      for(auto nbr: adj[node]){
          if(!vis[nbr]){
              dfs(nbr,vis,st,adj);
          }
      }
      st.push(node);
      return ;
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }
        
        stack<int>st;
        vector<int>vis(V,false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        
        vector<int>ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
