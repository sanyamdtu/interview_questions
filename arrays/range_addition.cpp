class Solution
{
public:
    /**
     * @param length: the length of the array
     * @param updates: update operations
     * @return: the modified array after all k operations were executed
     */
    vector<int> getModifiedArray(int n, vector<vector<int>> &q)
    {
        vector<int> dp(n + 1);
        for (int i = 0; i < n + 1; i++)
            dp[i] = 0;
        for (auto i : q)
        {
            dp[i[0]] += i[2];
            dp[i[1] + 1] += -i[2];
        }
        for (int i = 1; i < n + 1; i++)
            dp[i] += dp[i - 1];
        dp.pop_back();
        return dp;
    }
};