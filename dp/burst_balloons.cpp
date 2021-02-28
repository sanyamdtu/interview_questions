class Solution
{
public:
    int maxCoins(vector<int> &num)
    {
        if (num.size() == 0)
            return 0;
        vector<int> arr;
        arr.push_back(1);
        for (auto i : num)
            arr.push_back(i);
        arr.push_back(1);
        int n = arr.size();
        long long dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int gap = 2; gap < n; gap++)
        {
            for (int l = 0; l < n - gap; l++)
            {
                int r = l + gap;
                for (int i = l + 1; i < r; i++)
                {
                    dp[l][r] = max(dp[l][i] + dp[i][r] + arr[l] * arr[i] * arr[r], dp[l][r]);
                }
            }
        }
        return dp[0][n - 1];
    }
};