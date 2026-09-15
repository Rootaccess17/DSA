class Solution {
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>>adj;
        
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // this first BFS is used for first element of diameter.
        
        queue<int>q;
        q.push(0);
        vector<bool>vis(V,false);
        vis[0]=true;
        
        int farthest=0;
        while(!q.empty()){
            int sz= q.size();
            
            while(sz--){
                int node= q.front();
                
                farthest= node;
                q.pop();
                
                for(auto it: adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=true;
                    }
                }
            }
        }
        
        
        // this second BFS for finding second element of diameter 
        
        q=queue<int>();
        q.push(farthest);
        vis=vector<bool>(V,false);
        
        vis[farthest] = true;
        
        int diameter=0;
        while(!q.empty()){
            int sz= q.size();
            
            while(sz--){
                int node=q.front();
                q.pop();
                
                for(auto it: adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=true;
                    }
                }
            }
            
            diameter++;
        }
        
        return diameter-1;
    }
};
