class Solution
{
public:
    // Functiuon to return number of trees

    // Return the total number of BSTs possible with keys [1....N] inclusive.
    int count(int n)
    {

        if (n % 2 == 1)
            return 0;
        n = n / 2;
        if (n == 0 || n == 1)
            return 1;
        long long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] = ((dp[j] * dp[i - j - 1]) + dp[i]) % 1000000007;
            }
        }
        return dp[n];
    }
};
