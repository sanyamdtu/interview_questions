class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        if (n < m)
            return 0;
        if (m == 0)
            return 1;
        long long dp[m];
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                if (t[j] == s[i])
                {
                    if (j == m - 1)
                        dp[j]++;
                    else
                        dp[j] += dp[j + 1];
                }
            }
        }
        return dp[0];
    }
};