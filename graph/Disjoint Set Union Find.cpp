int find(int i,vector<int>&parent){
    if(i==parent[i]) return i;

    return (parent[i],parent);
}

void union(int x, int y, vector<int>&parent){
    int x_par= find(x,parent);
    int y_par= find(y,parent);

    if(x_par != y_par){
        parent[x_par] = y_par;
    }
}
