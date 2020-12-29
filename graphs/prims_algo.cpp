#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> g(n + 1);
    for (long long i = 0; i < m; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        g[a].pb({c, b});
        g[b].pb({c, a});
    }
    long long c = 1, ans = 0;
    set<pair<long long, long long>> s;
    for (auto i : g[1])
    {
        s.insert(i);
    }
    long long vis[n + 1];
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    while (c < n)
    {
        auto a = *(s.begin());
        s.erase(s.find(a));
        long long node = a.second;
        long long wt = a.first;
        if (vis[node] == 0)
        {
            vis[node] = 1;
            ans += wt;
            for (auto i : g[node])
                s.insert(i);
            c++;
        }
    }
    cout << ans;
}