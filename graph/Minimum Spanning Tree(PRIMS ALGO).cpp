class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto e: edges){
            int u= e[0];
            int v= e[1];
            int w= e[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>>pq; //{wt,node,par}
        
        vector<bool>mst(V,false); // find whether a node is in mst or not
        
        vector<int>parent(V,-1);  // parent arrray store parent of each node
        
        pq.push({0,0,-1});
        int sum=0;
        
        while(!pq.empty()){
            auto [wt,node,par] = pq.top();
            
            pq.pop();
             
            if(mst[node]==true) continue; // if already present in mst
             
            mst[node]=true;  // add into mst
            sum+=wt; // add in sum
            parent[node]=par;
            
        
            for(auto it: adj[node]){
                int adjnode=it.first;
                int adjwt= it.second;
                
                if(!mst[adjnode]){
                    pq.push({adjwt,adjnode,node});
                }
            }
        }
        
        return sum;
    }
};
