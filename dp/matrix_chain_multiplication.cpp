
class Solution
{
public:
    int matrixMultiplication(int n, int arr[])
    {
        if (n == 2)
            return 0;
        long long dp[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = INT_MAX;
        for (int i = 0; i < n - 1; i++)
            dp[i][i + 1] = 0;
        for (int gap = 2; gap < n; gap++)
        {
            for (int l = 0; l < n - gap; l++)
            {
                int r = l + gap;
                for (int i = l + 1; i < r; i++)
                {
                    dp[l][r] = min(dp[l][i] + dp[i][r] + arr[l] * arr[i] * arr[r], dp[l][r]);
                }
            }
        }
        return dp[0][n - 1];
    }
};