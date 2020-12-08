#include <bits/stdc++.h>
using namespace std;
int prim(vector<vector<pair<int, int>>> &g, int n)
{
    int c = 1;
    set<pair<int, int>> s;
    int vis[n];
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    for (auto i : g[0])
        s.insert(i);
    int ans = 0;
    while (c != n)
    {
        auto a = *(s.begin());
        s.erase(s.find(a));
        int node = a.second;
        int wt = a.first;
        if (vis[node] == 0)
        {
            vis[node] = 1;
            c++;
            for (auto i : g[node])
            {
                s.insert(i);
            }
            ans += wt;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        int a;
        cin >> a;
        g[i].push_back({a, 0});
        g[0].push_back({a, i});
    }
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }
    int cost = prim(g, n + 1);
    cout << cost;
}