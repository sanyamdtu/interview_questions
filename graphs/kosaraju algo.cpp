class Solution
{
public:
    //Function to find number of strongly connected components in the graph.
    int ans;
    int vis[10000];
    stack<int> s;
    void dfs(int u, vector<int> g[])
    {

        for (auto i : g[u])
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                dfs(i, g);
            }
        }
        s.push(u);
    }
    void dfsh(int u, vector<int> g[])
    {
        for (auto i : g[u])
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                dfsh(i, g);
            }
        }
    }
    int kosaraju(int n, vector<int> g[])
    {
        ans = 0;
        s = stack<int>();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, g);
            }
        }

        vector<int> arr[n];
        for (int i = 0; i < n; i++)
        {
            for (auto j : g[i])
            {
                arr[j].push_back(i);
            }
        }

        memset(vis, 0, sizeof(vis));
        while (!s.empty())
        {
            auto a = s.top();
            s.pop();
            if (vis[a] == 1)
                continue;
            vis[a] = 1;
            dfsh(a, arr);
            ans++;
        }
        return ans;
    }
};
