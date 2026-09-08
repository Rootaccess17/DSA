class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
         // we have to relax (V-1) times ***
        for(int i=1; i<=V-1; i++){
            for(auto e: edges){
                int u=e[0];
                int v=e[1];
                int w=e[2];
                
                if(dist[u]!=INT_MAX && dist[u]+w < dist[v]){
                    dist[v] = dist[u]+w;
                }
            }
        }

        // if it become true one more time then it contain negative weight cycle.
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
                
            if(dist[u]!=INT_MAX && dist[u]+w < dist[v]){
                
                return {-1};
            }
        }
        
        for(int i=0; i<V; i++){
            if(dist[i]==INT_MAX){
                dist[i]=1e8;
            }
        }
        
        return dist;
    }
};
