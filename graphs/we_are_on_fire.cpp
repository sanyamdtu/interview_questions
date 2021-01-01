#include <bits/stdc++.h>
using namespace std;
long long arr[2000][2000];
long long n, m, q;
long long dx[] = {-1, 0, 0, 1};
long long dy[] = {0, 1, -1, 0};
long long dfs(long long i, long long j)
{

    long long c = 1;
    arr[i][j] = 0;
    for (long long k = 0; k < 4; k++)
    {
        long long x = i + dx[k];
        long long y = j + dy[k];
        if (x >= 0 && y >= 0 && x < n && y < m && arr[x][y] == 1)
            c += dfs(x, y);
    }
    return c;
}
int main()
{
    long long ans = 0;
    cin >> n >> m >> q;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            scanf("%d", arr[i][j]);
            // cout<<arr[i][j]<<" ";
            if (arr[i][j] == 1)
                ans++;
        }
        // cout<<endl;
    }
    while (q--)
    {
        long long x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        // cout<<arr[x][y]<<" ";
        if (arr[x][y] == 1)
        {
            ans -= dfs(x, y);
        }
        printf("%d\n", ans);
    }
}