#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e;
        cin >> n >> e;
        vector<vector<pair<int, int>>> g(n + 1);
        while (e--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({c, b});
        }
        int a, b;
        cin >> a >> b;
        set<pair<int, int>> s;
        s.insert({0, a});
        int dis[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dis[i] = INT_MAX;
        }
        while (!s.empty())
        {
            auto p = *(s.begin());
            s.erase(s.begin());
            int node = p.second;
            int wt = p.first;
            if (dis[node] == INT_MAX)
            {
                dis[node] = wt;
                for (auto i : g[node])
                {
                    if (dis[i.second] == INT_MAX)
                    {
                        s.insert({i.first + wt, i.second});
                    }
                }
            }
        }
        dis[a] = 0;
        if (dis[b] == INT_MAX)
            cout << "NO";
        else
            cout << dis[b];
        cout << endl;
    }
}
