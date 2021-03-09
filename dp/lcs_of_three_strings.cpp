int LCSof3(string a, string b, string c, int n, int m, int o)
{
    int dp[n + 1][m + 1][o + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            for (int k = o - 1; k >= 0; k--)
            {
                if (a[i] == b[j] && a[i] == c[k])
                    dp[i][j][k] = dp[i + 1][j + 1][k + 1] + 1;
                else
                    dp[i][j][k] = max(dp[i][j][k + 1], max(dp[i + 1][j][k], dp[i][j + 1][k]));
            }
        }
    }
    return dp[0][0][0];
}