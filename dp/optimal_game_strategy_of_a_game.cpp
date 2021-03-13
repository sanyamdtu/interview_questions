
long long maximumAmount(int arr[], int n)
{
    long long dp[n][n];
    for (int i = 0; i < n; i++)
        dp[i][i] = arr[i];
    for (int i = 1; i < n; i++)
    {
        dp[i - 1][i] = max(arr[i], arr[i - 1]);
    }
    for (int gap = 2; gap < n; gap++)
    {
        for (int l = 0; l < n - gap; l++)
        {
            int r = l + gap;
            int a = min(dp[l + 1][r - 1], dp[l + 2][r]) + arr[l];
            int b = min(dp[l + 1][r - 1], dp[l][r - 2]) + arr[r];
            dp[l][r] = max(a, b);
        }
    }
    return dp[0][n - 1];
}