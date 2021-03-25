class Solution {
public:
    bool isMatch(string s, string p) {
        if(s==p)
            return true;
        int n=s.length(),m=p.length();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=m;i++)
            if(p[i-1]=='*')
                dp[0][i]=dp[0][i-1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    if(dp[i-1][j-1]+dp[i-1][j]+dp[i][j-1]>0)
                        dp[i][j]=1;
                }
                else{
                    if(p[j-1]==s[i-1])
                        dp[i][j]=dp[i-1][j-1];
                }
            }
        }
        return (dp[n][m]==1);
    }
};