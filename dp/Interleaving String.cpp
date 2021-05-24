int dp[300][300];
class Solution
{
public:
    int p, q, r;
    string x;
    string y;
    string z;
    bool func(int i, int j, int k)
    {
        if (k == r)
            return (i == p && j == q);
        if (x[i] != z[k] && y[j] != z[k])
            return false;
        if (dp[i][j] != -1)
            return (dp[i][j] == 1);
        bool ans = false;
        if (x[i] == z[k])
            ans = ans | func(i + 1, j, k + 1);
        if (y[j] == z[k])
            ans = ans | func(i, j + 1, k + 1);
        dp[i][j] = 0;
        if (ans)
            dp[i][j] = 1;
        return ans;
    }
    bool isInterleave(string a, string b, string c)
    {
        p = a.length();
        q = b.length();
        r = c.length();
        memset(dp, -1, sizeof(dp));
        x = a;
        y = b;
        z = c;
        if (p + q != r)
            return false;
        return func(0, 0, 0);
    }
};