
int wordBreak(string a, vector<string> &b)
{
    unordered_map<string, int> m;
    int n = a.length();
    for (auto i : b)
    {
        reverse(i.begin(), i.end());
        m[i] = 1;
    }

    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 0;
    for (int i = 0; i < n; i++)
    {
        string temp = "";
        for (int j = i; j >= 0; j--)
        {
            temp += a[j];
            if (dp[i] == 0 && m[temp] == 1)
            {
                if (j != 0)
                    dp[i] = dp[j - 1];
                else
                    dp[i] = 1;
            }
        }
    }
    return dp[n - 1];
}