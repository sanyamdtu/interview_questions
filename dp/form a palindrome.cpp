
class Solution
{
public:
    int countMin(string s)
    {
        int n = s.length();
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        for (int gap = 2; gap <= n; gap++)
        {
            for (int l = 0; l <= n - gap; l++)
            {
                int r = l + gap - 1;
                if (s[l] == s[r])
                {
                    dp[l][r] = dp[l + 1][r - 1] + 2;
                }
                else
                {
                    dp[l][r] = max(dp[l + 1][r], max(dp[l][r - 1], dp[l + 1][r - 1]));
                }
            }
        }
        return n - dp[0][n - 1];
    }
};
