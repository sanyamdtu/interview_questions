#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back({0, y});
        g[y].push_back({1, x});
    }
    set<pair<int, int>> s;
    int dis[n + 1], vis[n + 1];
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    for (auto i : g[1])
    {
        s.insert(i);
    }
    vis[1] = 1;
    dis[1] = 0;
    while (!s.empty())
    {
        auto a = *(s.begin());
        s.erase(s.begin());
        int node = a.second;
        int wt = a.first;
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        dis[node] = wt;
        for (auto i : g[node])
        {
            if (vis[i.second] == 0)
            {
                s.insert({wt + i.first, i.second});
            }
        }
    }
    cout << dis[n];
}
