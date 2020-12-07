class Solution
{
public:
    bool isBipartite(vector<vector<int>> &g)
    {
        int n = g.size();
        if (n <= 2)
            return true;
        int vis[n];
        memset(vis, -1, sizeof(vis));
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == -1)
            {
                queue<int> q;
                q.push(i);
                vis[i] = 0;
                while (!q.empty())
                {
                    int a = q.front();
                    q.pop();
                    for (auto j : g[a])
                    {
                        if (vis[j] == vis[a])
                            return false;
                        if (vis[j] == -1)
                            q.push(j);
                        vis[j] = 1 - vis[a];
                    }
                }
            }
        }
        return true;
    }
};