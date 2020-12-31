#include <bits/stdc++.h>
using namespace std;
#define mod 100000
long long vis[mod + 5];

queue<pair<long long, long long>> q;
int main()
{
    long long a, b;
    cin >> a >> b;
    a %= mod;
    b %= mod;
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] %= mod;
    }
    memset(vis, 0, sizeof(vis));
    q.push({a, 0});
    long long ans = -1;
    vis[a] = 1;
    while (!q.empty())
    {
        auto p = q.front();
        if (p.first == b)
        {
            ans = p.second;
            break;
        }
        q.pop();
        for (long long i = 0; i < n; i++)
        {
            long long c = ((p.first * arr[i]) % mod);
            if (vis[c] == 0)
            {
                q.push({c, p.second + 1});
                vis[c] = 1;
            }
        }
    }
    cout << ans;
}