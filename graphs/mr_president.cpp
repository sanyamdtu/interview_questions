#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x, y, d;
};
bool comp(node a, node b)
{
    return (a.d < b.y);
}
int find(int x, int p[])
{
    if (p[x] == x)
        return x;
    return p[x] = find(p[x], p);
}
void un(int x, int y, int p[], int r[])
{
    int px = find(x, p);
    int py = find(y, p);
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
int main()
{
    //long long must
    int n, m, k;
    cin >> n >> m >> k;
    node arr[m];
    int p[n + 1], r[n + 1];
    memset(r, 0, sizeof(r));
    for (int i = 0; i < n + 1; i++)
        p[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> arr[i].x >> arr[i].y >> arr[i].d;
    }
    sort(arr, arr + m, comp);
    int c = 0;
    int i = 0;
    int ans = 0;
    while (c != n - 1)
    {
        if (find(arr[i].x, p) != find(arr[i].y, p))
        {
            c++;
            un(arr[i].x, arr[i].y, p, r);
            ans += arr[i].d;
        }
    }
}