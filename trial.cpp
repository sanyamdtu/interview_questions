#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x != y)
        {
            g[x].push_back({0, y});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : g[i])
        {
            g[j.second].push_back({1, i});
        }
    }
    int dis[n + 1], vis[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dis[i] = INT_MAX;
        vis[i] = 0;
    }
    dis[1] = 0;
    set<pair<int, int>> s;
    s.insert({1, 0});
}
