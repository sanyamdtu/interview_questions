
class Solution
{
public:
    double findProb(int n, int x, int y, int k)
    {
        double dp[n][n][k + 1];
        for (int l = k + 1; l >= 0; l--)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dp[i][j][l] = 0;
                }
            }
        }
        dp[x][y][k] = 1;
        int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
        int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        for (int l = k; l >= 1; l--)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int p = 0; p < 8; p++)
                    {
                        int a = i + dx[p];
                        int b = j + dy[p];
                        if (a >= 0 && b >= 0 && a < n && b < n)
                        {
                            dp[a][b][l - 1] += ((double)(0.125)) * dp[i][j][l];
                        }
                    }
                }
            }
        }
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans += dp[i][j][0];
            }
        }

        return ans;
    }
};
