#include <bits/stdc++.h>
using namespace std;
int vis[30005], ap[30005], dis[30005], low[30005], par[30005], p, c;
void dfs(int u, vector<vector<int>> &g)
{
    vis[u] = 1;
    dis[u] = p;
    low[u] = p;
    p++;
    for (auto i : g[u])
    {
        if (par[u] == i)
            continue;
        if (vis[i] == 1)
        {
            low[u] = min(low[u], dis[i]);
        }
        else
        {
            if (u == 1)
                c++;
            par[i] = u;
            dfs(i, g);
            low[u] = min(low[u], low[i]);
        }
        if (u != 1 && dis[u] <= low[i])
            ap[u] = 1;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        c = p = 0;
        cin >> n >> m;
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        memset(vis, 0, sizeof(vis));
        memset(ap, 0, sizeof(ap));
        memset(par, -1, sizeof(par));
        dfs(1, g);
        if (c > 1)
            ap[1] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ap[i] == 1)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}