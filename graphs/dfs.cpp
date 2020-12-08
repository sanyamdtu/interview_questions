
/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
void func(int src, vector<int> g[], int vis[], vector<int> &v)
{
    vis[src] = 1;
    v.push_back(src);
    for (auto i : g[src])
    {
        if (vis[i] == 0)
        {
            func(i, g, vis, v);
        }
    }
}
vector<int> dfs(vector<int> g[], int n)
{
    vector<int> v;
    int vis[n];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            func(i, g, vis, v);
        }
    }
    return v;
}
