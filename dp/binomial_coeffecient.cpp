
class Solution
{
public:
    int nCr(int n, int r)
    {
        long long dp[n + 1][r + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }
        dp[1][1] = 1;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < r + 1; j++)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 1000000007;
            }
        }
        return dp[n][r];
    }
};
