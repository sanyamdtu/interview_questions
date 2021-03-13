typedef long long ll;
int countPS(string s)
{
    int n = s.length();
    ll dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int gap = 1; gap <= n - 1; gap++)
    {
        for (int l = 0; l < n - gap; l++)
        {
            int r = l + gap;
            if (s[l] == s[r])
                dp[l][r] = dp[l + 1][r] + 1 + dp[l][r - 1];
            else
            {
                dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1];
            }
        }
    }
    return dp[0][n - 1];
}
