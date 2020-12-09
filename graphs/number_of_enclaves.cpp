class Solution
{
public:
    int n, m;
    void func(vector<vector<int>> &arr, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || arr[i][j] == 0)
            return;
        arr[i][j] = 0;
        func(arr, i + 1, j);
        func(arr, i - 1, j);
        func(arr, i, j - 1);
        func(arr, i, 1 + j);
    }
    int numEnclaves(vector<vector<int>> &arr)
    {
        n = arr.size();
        m = arr[0].size();
        for (int i = 0; i < n; i++)
        {
            func(arr, i, 0);
            func(arr, i, m - 1);
        }
        for (int i = 0; i < m; i++)
        {
            func(arr, 0, i);
            func(arr, n - 1, i);
        }
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                    c++;
            }
        }
        return c;
    }
};