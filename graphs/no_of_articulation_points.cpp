#include <bits/stdc++.h>
using namespace std;
int c = 0, dis[1000], par[1000], low[1000], vis[1000], t = 0, ans[1000];
void dfs(int u, vector<vector<int>> &g)
{
    cout << u << " ";
    low[u] = dis[u] = t;
    vis[u] = 1;
    t++; //time
    for (auto j : g[u])
    {
        if (par[u] == j)
            continue;
        if (vis[j] == 1)
        {
            low[u] = min(low[u], dis[j]);
        }
        else
        {
            if (u == 0)
                c++;
            par[j] = u;
            dfs(j, g);
            low[u] = min(low[u], low[j]);
        }
        if (u != 0 && dis[u] <= low[j])
            ans[u] = 1;
    }
}
int main()
{
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<vector<int>> g(n);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        vis[i] = 0;
        ans[i] = 0;
    }
    dfs(0, g);
    if (c > 1)
        ans[0] = 1;
    int res = 0;
    for (int i = 0; i < n; i++)
        if (ans[i] == 1)
            res++;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " " << par[i] << " " << dis[i] << low[i] << endl;
    }

    cout << res;
}

// 8 10 0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 5 3 0 2 7