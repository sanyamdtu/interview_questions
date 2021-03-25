class Solution
{
public:
    int minCut(string s)
    {
        int n = s.length();
        int m[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                m[i][j] = 1;
        for (int i = 0; i < n; i++)
            m[i][i] = 1;
        for (int gap = 1; gap < n; gap++)
        {
            for (int l = 0; l < n - gap; l++)
            {
                int r = l + gap;
                if (s[l] == s[r])
                    m[l][r] = m[l + 1][r - 1];
                else
                    m[l][r] = 0;
            }
        }
        int dp[n];
        for (int i = 0; i < n; i++)
            dp[i] = i;
        for (int i = 0; i < n; i++)
        {
            if (m[0][i] == 1)
            {
                dp[i] = 0;
                continue;
            }
            for (int j = i; j > 0; j--)
            {
                if (m[j][i] == 1)
                    dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
        return dp[n - 1];
    }
};