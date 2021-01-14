class Solution
{
public:
    int trapRainWater(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        bool vis[n][m];
        if (n <= 2 || m <= 2)
            return 0;
        int ans = 0;
        memset(vis, false, sizeof(vis));
        multiset<pair<int, pair<int, int>>> s;
        for (int i = 0; i < m; i++)
        {
            vis[0][i] = true;
            vis[n - 1][i] = true;
            s.insert({arr[0][i], {0, i}});
            s.insert({arr[n - 1][i], {n - 1, i}});
        }
        for (int i = 1; i < n - 1; i++)
        {
            vis[i][0] = true;
            vis[i][m - 1] = true;
            s.insert({arr[i][0], {i, 0}});
            s.insert({arr[i][m - 1], {i, m - 1}});
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while (!s.empty())
        {
            auto a = *(s.begin());
            auto d = a.second;
            s.erase(s.begin());
            for (int i = 0; i < 4; i++)
            {
                int x = dx[i] + d.first;
                int y = dy[i] + d.second;
                if (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y])
                {
                    if (arr[x][y] >= a.first)
                    {
                        vis[x][y] = true;
                        s.insert({arr[x][y], {x, y}});
                    }
                    else
                    {
                        vis[x][y] = true;
                        ans += a.first - arr[x][y];
                        s.insert({a.first, {x, y}});
                    }
                }
            }
        }
        return ans;
    }
};