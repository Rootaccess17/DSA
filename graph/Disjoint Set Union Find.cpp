int find(int i,vector<int>&parent){
    if(i==parent[i]) return i;

    return parent[i] = find(parent[i],parent);
}

void union(int x, int y, vector<int>&parent,vector<int>&rank){
    int x_par= find(x,parent);
    int y_par= find(y,parent);

    if(x_par == y_par){
        return;
    }
    else if(rank[x_par] > rank[y_par]){
        parent[y_par] = x_par;
    }
    else if(rank[y_par] > rank[x_par]){
        parent[x_par] = y_par;
    }
    else{
        parent[x_par] = y_par;
        rank[y_par] += 1;
    }
}
