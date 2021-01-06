#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int in[n + 1];
    memset(in, 0, sizeof(in));
    vector<unordered_set<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
        in[a]++;
        in[b]++;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (auto j : g[i])
        {
            for (auto k : g[j])
            {
                if (g[k].find(i) != g[k].end())
                {
                    ans = min(ans, in[i] + in[j] + in[k] - 6);
                }
            }
        }
    }
    if (ans == INT_MAX)
        ans = -1;
    cout << ans;
}