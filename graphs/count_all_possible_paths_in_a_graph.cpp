#include <bits/stdc++.h>
using namespace std;
int dis[200][200];
void dfs(vector<vector<int>> &g, int src, int dis[][200], int u, int v, int vis[])
{
    if (v == src)
    {
        dis[u][v]++;
        return;
    }
    for (auto i : g[src])
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            dfs(g, i, dis, u, v, vis);
            vis[i] = 0;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int vis[n];
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vis[i] = 1;
            dfs(g, i, dis, i, j, vis);
            vis[i] = 0;
        }
    }
}