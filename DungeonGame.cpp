class Solution {
public:
    #define ll long long
    typedef vector<vector<int>> vvi;
    typedef vector<int> vi;   
    int n,m;
    
    int dfs(vvi &g, vvi &dp, int i, int j){
        if(i==n-1 && j==m-1)
            return g[i][j]>=0 ? -1*g[i][j]:abs(g[i][j]);
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        ll r=INT_MAX, d=INT_MAX, tmp;
        tmp = g[i][j]>=0 ? -1*g[i][j]:abs(g[i][j]);
        
        if((j+1)<m) r = max(tmp, tmp+dfs(g, dp, i, j+1));
        if((i+1)<n) d = max(tmp, tmp+dfs(g, dp, i+1, j));
        
        dp[i][j] = min(r, d);
        return dp[i][j];
        
    }
      
    int calculateMinimumHP(vvi& g) {
        n=g.size();
        m=g[0].size();
        vvi dp(n, vi(m, -1));
        ll ans = dfs(g, dp, 0, 0);
        return ans>=0 ? ans+1:1;
    }
};
