int dp[200][60000];
class Solution
{
public:
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            sum += arr[i];
        if (sum % 2 == 1)
            return 0;
        sum /= 2;
        dp[0][0] = 1;
        dp[0][arr[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (dp[i - 1][j] == 1)
                    dp[i][j] = 1;
                else if (j - arr[i] >= 0)
                    dp[i][j] = dp[i - 1][j - arr[i]];
            }
        }
        for (int i = 0; i < n; i++)
            if (dp[i][sum] == 1)
                return 1;
        return 0;
    }
};
