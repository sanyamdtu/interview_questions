#include <bits/stdc++.h>
using namespace std;
bool bfs(int g[200][200], int vis[], int par[], int n)
{
    queue<int> q;
    vis[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        auto a = q.front();
        q.pop();
        if (a == n)
            break;
        for (int i = 1; i < n + 1; i++)
        {
            if (g[a][i] > 0 && vis[i] == 0)
            {
                par[i] = a;
                vis[i] = 1;
                q.push({i});
            }
        }
    }
    return (par[n] != -1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int g[200][200];
        memset(g, 0, sizeof(g));
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            g[x][y] = z;
        }
        int par[n + 1], vis[n + 1];
        memset(par, -1, sizeof(par));
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        while (bfs(g, vis, par, n))
        {
            int minc = INT_MAX;
            for (int i = n; i != 1; i = par[i])
            {
                minc = min(minc, g[par[i]][i]);
            }
            for (int i = n; i != 1; i = par[i])
            {
                g[i][par[i]] += minc;
                g[par[i]][i] -= minc;
            }
            ans += minc;
            memset(par, -1, sizeof(par));
            memset(vis, 0, sizeof(vis));
        }
        cout << ans << endl;
    }
}