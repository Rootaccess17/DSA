class Solution {
public:
vector<vector<string>>ans;
void solve(int i,string &s,vector<vector<bool>>&t,vector<string>&st){
    int n=s.size();
    if(i==n){
        ans.push_back(st);
        return ;
    }

    for(int j=i; j<n; j++){
        if(t[i][j]==true){
            st.push_back(s.substr(i,j-i+1));
            solve(j+1,s,t,st);
            st.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>>t(n,vector<bool>(n,false));

        for(int i=0; i<n; i++){
            t[i][i]=true;
        }
        for(int L=2; L<=n; L++){
            for(int i=0; i<n-L+1; i++){
                int j=L+i-1;

                if(s[i]==s[j]){
                    if(L==2){
                       t[i][j]=true; 
                    }
                    else{
                        t[i][j]=t[i+1][j-1];
                    }
                }
            }
        }
        vector<string>st;
        solve(0,s,t,st);

        return ans;
    }
};
