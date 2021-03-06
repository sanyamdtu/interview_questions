class Solution
{
public:
    int n;
    int func(int a, int b, int c, int d, vector<vector<int>> &arr, int dp[][60][60][60])
    {
        if (a < 0 || a >= n || b < 0 || b >= n || c < 0 || c >= n || d < 0 || d >= n || arr[a][b] == -1 || arr[c][d] == -1)
            return INT_MIN;
        int ans = 0;
        if (a == n - 1 && b == n - 1)
            return arr[a][b];
        if (dp[a][b][c][d] != INT_MAX)
            return dp[a][b][c][d];
        if (a == c && b == d)
            ans += arr[a][b];
        else
            ans += arr[a][b] + arr[c][d];
        int p = func(a + 1, b, c + 1, d, arr, dp);
        int q = func(a + 1, b, c, d + 1, arr, dp);
        int r = func(a, b + 1, c, d + 1, arr, dp);
        int s = func(a, b + 1, c + 1, d, arr, dp);
        return dp[a][b][c][d] = max(p, max(q, max(r, s))) + ans;
    }
    int cherryPickup(vector<vector<int>> &arr)
    {
        n = arr.size();
        int dp[n][60][60][60];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < n; l++)
                        dp[i][j][k][l] = INT_MAX;
                }
            }
        }
        return max(func(0, 0, 0, 0, arr, dp), 0);
    }
};