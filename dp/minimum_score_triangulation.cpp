class Solution
{
public:
    int minScoreTriangulation(vector<int> &arr)
    {
        int n = arr.size();
        int ans = INT_MAX;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int gap = 2; gap < n; gap++)
        {
            for (int l = 0; l < n - gap; l++)
            {
                int r = l + gap;
                dp[l][r] = INT_MAX;
                for (int i = l + 1; i < r; i++)
                {
                    dp[l][r] = min(dp[l][i] + dp[i][r] + arr[l] * arr[i] * arr[r], dp[l][r]);
                }
            }
        }

        return dp[0][n - 1];
    }
};