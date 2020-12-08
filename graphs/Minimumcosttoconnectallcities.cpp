#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int c = 1, ans = 0;
    set<pair<int, int>> s;
    int vis[n];

    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] != 0)
        {
            s.insert({arr[i][0], i});
        }
    }
    vis[0] = 1;
    while (c != n)
    {
        auto a = *(s.begin());
        s.erase(s.find(a));
        int wt = a.first;
        int node = a.second;
        if (vis[node] == 0)
        {
            vis[node] = 1;
            c++;
            ans += wt;
            cout << node << " " << wt;
            for (int i = 0; i < n; i++)
            {
                if (arr[i][node] != 0)
                    s.insert({arr[i][node], i});
            }
        }
    }
    cout << ans;
}