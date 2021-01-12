#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long x, y, d;
};
bool comp(node a, node b)
{
    return (a.d < b.d);
}
long long find(long long x, long long p[])
{
    if (p[x] == x)
        return x;
    return p[x] = find(p[x], p);
}
void un(long long x, long long y, long long p[], long long r[])
{
    long long px = find(x, p);
    long long py = find(y, p);
    if (r[px] > r[py])
        p[py] = px;
    else if (r[px] < r[py])
        p[px] = py;
    else
    {
        r[px]++;
        p[py] = px;
    }
}
long long p[2000000], r[2000000];
int main()
{
    //long long must
    long long n, m, k;
    cin >> n >> m >> k;
    node arr[m];

    memset(r, 0, sizeof(r));
    for (long long i = 0; i < n + 1; i++)
        p[i] = i;
    for (long long i = 0; i < m; i++)
    {
        long long a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        arr[i].x=a;
        arr[i].y=b;
        arr[i].d=c;
    }
    sort(arr, arr + m, comp);
    long long c = 0;
    long long i = 0;
    long long ans = 0;
    vector<long long> v;
    while (c < n - 1 && i < m)
    {
        if (find(arr[i].x, p) != find(arr[i].y, p))
        {

            c++;
            un(arr[i].x, arr[i].y, p, r);
            ans += arr[i].d;
            v.push_back(arr[i].d);
        }
        i++;
    }

    long long f = 0;
    for (long long i = 2; i <= n; i++)
    {
        if (find(i, p) != find(i - 1, p))
        {
            f = 1;
            break;
        }
    }
    long long mini = 0;
    if (f == 0)
    {
        if(ans>k)
        for (long long i = v.size() - 1; i >= 0; i--)
        {
            mini++;
            ans += 1 - v[i];
            if (ans <= k)
                break;
        }
    }
    if (f == 0 && ans <= k)
        cout << mini;
    else
        cout << -1;
}