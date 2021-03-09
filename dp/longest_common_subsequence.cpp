class Solution
{
public:
    int longestCommonSubsequence(string s, string t)
    {
        int n = s.length(), m = t.length();
        int dp[m + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; i--)
        {
            int ip1jp1 = 0;
            for (int j = m - 1; j >= 0; j--)
            {
                int temp = dp[j];
                if (s[i] == t[j])
                {
                    dp[j] = ip1jp1 + 1;
                }
                else
                    dp[j] = max(dp[j + 1], dp[j]);
                ip1jp1 = temp;
            }
        }
        return dp[0];
    }
};