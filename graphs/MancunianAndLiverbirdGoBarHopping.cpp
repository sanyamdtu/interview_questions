#include <bits/stdc++.h>
using namespace std;
int dfs(int a, vector<vector<int>> &g, int ans[])
{
    ans[a]++;
    for (auto i : g[a])
    {
        if (ans[i] == 0)
            ans[i] = dfs(i, g, ans);
        ans[a] += ans[i];
    }
    return ans[a];
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
    int q;
    cin >> q;
    int f = 0; //sign
    int arr[n], rev[n];
    memset(arr, 0, sizeof(arr));
    memset(rev, 0, sizeof(rev));
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            dfs(i, g, arr);
        if (rev[i] == 0)
            dfs(i, p, rev);
    }
    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == 'Q')
        {
            int x;
            cin >> x;
            if (f == 0)
                cout << arr[x - 1] << endl;
            else
                cout << rev[x - 1] << endl;
        }
        else
            f = 1 - f;
    }
}