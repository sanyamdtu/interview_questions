
int eggDrop(int k, int n)
{
    int dp[n + 1][k + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            dp[i][j] = 0;
    for (int i = 0; i <= n; i++)
    {
        dp[i][1] = i;
    }
    for (int j = 1; j <= k; j++)
    {
        dp[1][j] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + 1 + dp[i - 1][j];
        }
    };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (dp[i][j] >= n)
            {
                return i;
            }
        }
    }
    return n;
}