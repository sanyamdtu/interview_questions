class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> arr)
    {
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            dp[i][m - 1] = arr[i][m - 1];
        }
        for (int i = 0; i < m; i++)
        {
            dp[n - 1][i] = arr[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = m - 2; j >= 0; j--)
            {
                if (arr[i][j] == 1)
                    dp[i][j] = 1 + min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1]));
                else
                    dp[i][j] = 0;
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};