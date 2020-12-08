
int c;
void dfs(int src, int vis[], vector<int> g[], stack<int> &s)
{
    vis[src] = 1;
    for (auto i : g[src])
    {
        if (vis[i] == 0)
        {
            dfs(i, vis, g, s);
        }
    }
    s.push(src);
}
int kosaraju(int n, vector<int> g[])
{
    int vis[n];
    stack<int> s;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, vis, g, s);
        }
    }
    memset(vis, 0, sizeof(vis));
    c = 0;
    vector<int> p[n];
    for (int i = 0; i < n; i++)
    {
        for (auto j : g[i])
        {
            p[j].push_back(i);
        }
    }
    while (!s.empty())
    {
        int a = s.top();
        s.pop();
        if (vis[a] == 0)
        {
            dfs(a, vis, p, s);
            c++;
        }
    }
    return c;
}