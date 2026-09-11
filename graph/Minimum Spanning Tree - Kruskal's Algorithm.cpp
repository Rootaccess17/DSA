class Solution {
  public:
  vector<int>parent;
  int find(int i){
      if(i==parent[i]) return i;
      
      return parent[i] = find(parent[i]);
  }
  void unionfind(int x,int y){
      int x_par= find(x);
      int y_par= find(y);
      
      if(x_par != y_par){
          
          parent[x_par] = y_par;
          
      }
  }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        
        int n=edges.size();
        
        // we sort it so that we connect first with small weight
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
            return a[2] < b[2];
        });
        
        parent.resize(V);
        for(int i=0; i<V; i++){
            parent[i]=i;
        }
        
        int sum=0;
        for(int i=0; i<n; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            int u_par= find(u);
            int v_par= find(v);
            
            if(u_par != v_par){  // checking already connected or not
                unionfind(u,v);
                sum+=wt;
            }
        }
        
        return sum;
    }
};
