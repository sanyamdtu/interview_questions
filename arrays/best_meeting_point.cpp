class Solution
{
public:
    /**
     * @param grid: a 2D grid
     * @return: the minimize travel distance
     */
    int minTotalDistance(vector<vector<int>> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;
        int m = arr[0].size();
        vector<int> x, y;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int a = x.size();
        int b = y.size();
        int p, q;
        p = x[a / 2];
        q = y[b / 2];
        long long ans = 0;
        for (auto i : x)
        {
            ans += abs(i - p);
        }
        for (auto i : y)
        {
            ans += abs(i - q);
        }
        return ans;
    }
};