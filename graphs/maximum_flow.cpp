#include <bits/stdc++.h>
using namespace std;
bool bfs(int a, vector<vector<pair<int, int>>> &g, int vis[], int par[])
{
    queue<pair<int, int>> q;
    vis[1] = 1;
    while (!q.empty())
    {
        auto a = q.front();
        q.pop();
        for (auto i : g[a.first])
        {
            if (vis[i.first] == 0)
            {
                q.push()
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> g(n + 1);
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            g[x].push_back({y, z});
        }
    }
}