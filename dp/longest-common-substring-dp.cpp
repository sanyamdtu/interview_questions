
class Solution{
    public:
    
    int longestCommonSubstr (string s, string t, int n, int m)
    {
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                ans=max(ans,dp[i][j]);
        return ans;
    }
};
