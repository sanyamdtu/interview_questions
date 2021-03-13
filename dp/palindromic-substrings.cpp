class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        if (n == 0)
            return 0;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int gap = 1; gap < n; gap++)
        {
            for (int l = 0; l < n - gap; l++)
            {
                int r = l + gap;
                if (s[l] == s[r])
                {
                    if (l + 1 != r)
                        dp[l][r] = dp[l + 1][r - 1];
                    else
                        dp[l][r] = 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dp[i][j] == 1)
                    ans++;
        return ans;
    }
};