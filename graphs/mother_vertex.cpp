
void dfs(vector<int> g[], int vis[], int src, stack<int> &s)
{
    for (auto i : g[src])
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            dfs(g, vis, i, s);
        }
    }
    s.push(src);
}
int findMother(int n, vector<int> g[])
{
    int vis[n];
    memset(vis, 0, sizeof(vis));
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            dfs(g, vis, i, s);
        }
    }
    memset(vis, 0, sizeof(vis));
    int a = s.top();
    vis[a] = 1;
    dfs(g, vis, a, s);
    for (int i = 0; i < n; i++)
        if (vis[i] == 0)
            return -1;
    return a;
}
