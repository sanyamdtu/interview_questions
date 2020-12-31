
bool bfs(int par[], int vis[], int g[100][100], int n)
{

    queue<int> q;
    vis[0] = 1;
    q.push(0);
    while (!q.empty())
    {
        auto a = q.front();
        q.pop();
        if (a == n)
            break;
        for (int i = 0; i <= n; i++)
        {
            if (g[a][i] > 0 && vis[i] == 0)
            {
                vis[i] = 1;
                q.push(i);
                par[i] = a;
            }
        }
    }
    return (par[n] != -1);
    // return (f==0);
}
int maxBPM(bool a[M][N], int m, int n)
{

    int g[100][100];
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == true)
            {
                g[i + 1][j + m + 1] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        g[0][i + 1] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        g[i + m + 1][n + m + 1] = 1;
    }
    int ans = 0, par[n + m + 2], vis[n + m + 2];
    memset(par, -1, sizeof(par));
    memset(vis, 0, sizeof(vis));
    while (bfs(par, vis, g, n + m + 1))
    {
        f = 1;
        int minc = INT_MAX;
        for (int i = n + m + 1; i != 0; i = par[i])
        {
            minc = min(minc, g[par[i]][i]);
        }

        ans += minc;
        for (int i = n + m + 1; i != 0; i = par[i])
        {
            g[par[i]][i] -= minc;
            g[i][par[i]] += minc;
        }
        memset(par, -1, sizeof(par));
        memset(vis, 0, sizeof(vis));
        // cout<<"pop";
    }
    return ans;
    return 0;
}