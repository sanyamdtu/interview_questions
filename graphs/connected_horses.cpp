#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long arr[2000][2000];
long long n, m, q;
long long dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
long long dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
long long dfs(long long arr[][2000], long long i, long long j)
{
    long long ans = 1;
    arr[i][j] = 0;
    for (long long k = 0; k < 8; k++)
    {
        long long x = i + dx[k];
        long long y = j + dy[k];
        if (x >= 0 && y >= 0 && x < n && y < m && arr[x][y] == 1)
        {
            ans += dfs(arr, x, y);
        }
    }
    return ans;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long ans = 1;
        cin >> n >> m >> q;
        memset(arr, 0, sizeof(arr));
        while (q--)
        {
            long long x, y;
            cin >> x >> y;
            arr[x][y] = 1;
        }
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    long long k = dfs(arr, i, j);
                    long long p = 1;
                    for (long long i = 1; i <= k; i++)
                    {
                        p = (p * i) % mod;
                    }
                    ans = (ans * p) % mod;
                }
            }
        }
        cout << ans << endl;
    }
}