#include <bits/stdc++.h>
using namespace std;
int dfs(int a, vector<vector<int>> &g, int vis[], int ans[])
{

    int ans = 0;
    for (auto i : g[a])
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            ans[i] = dfs(i, g, vis, ans);
        }
        ans[a] += ans[i];
    }
    return vis[a];
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n), p(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            g[i].push_back(i + 1);
            p[i + 1].push_back(i);
        }
        else
        {
            g[i + 1].push_back(i);
            p[i].push_back(i + 1);
        }
    }
    int og[n], rev[n], vis[n];
    for (int i = 0; i < n; i++)
    {
        og[i] = 1, rev[i] = 1, vis[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            og[i] = 1;
            int c = dfs(i, g, vis, og);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            rev[i] = 1;
            int c = dfs(i, g, vis, rev);
        }
    }
    int q;
    cin >> q;
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        cout << og[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << rev[i] << " ";
    }
    cout << endl;
    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == 'Q')
        {
            int x;
            cin >> x;
            if (f == 0)
                cout << og[x - 1] << endl;
            else
                cout << rev[x - 1] << endl;
        }
        else
        {
            f = 1 - f;
        }
    }
}