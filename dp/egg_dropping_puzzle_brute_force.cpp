
int eggDrop(int k, int n)
{
    int dp[n + 1][k + 1];
    memset(dp, 10000, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = i;
    }
    for (int j = 0; j <= k; j++)
    {
        dp[0][j] = 0;
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            if (i >= j)

                for (int l = 1; l <= i; l++)
                    dp[i][j] = min(max(dp[l - 1][j - 1], dp[i - l][j]) + 1, dp[i][j]);
        }
        else dp[i][j] = dp[i][j - 1];
    }
    return dp[n][k];
}
