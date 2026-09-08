class Solution {
public:
int dp[2001];
int solve(int i,string &s,vector<vector<bool>>&t){
    int n=s.size();
    if(i==n) return -1;  // this is for last palindrom beacuse it count it so we have to neutralize it.
    if(dp[i]!=-1) return dp[i];
    int ans= INT_MAX;
    for(int j=i; j<n; j++){
        if(t[i][j]==true){
            ans= min(ans,1+solve(j+1,s,t));
        }
    }
    return dp[i]=ans;
}
    int minCut(string s) {
        int n=s.size();

        vector<vector<bool>>t(n,vector<bool>(n,false));
// BLUEPRINT*****
        for(int i=0; i<n; i++){
            t[i][i]=true;
        }

        for(int L=2; L<=n; L++){
            for(int i=0; i<n-L+1; i++){
                int j=L+i-1;

                if(s[i]==s[j]){
                    if(L==2){
                        t[i][j] = true;
                    }
                    else{
                        t[i][j] = t[i+1][j-1];
                    }
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,s,t);
    }
};
