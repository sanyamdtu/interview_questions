#include <bits/stdc++.h>
using namespace std;
int a[1000], b[1000];
int n;
int func(int i, int j)
{

    if (i == n && j == n)
        return 1;
    if (i == n || j == n)
    {
        return 0;
    }

    if (a[i] != b[j])
    {
        // cout << "pop";

        return 0;
    }

    int data = a[i];
    int l, u, p, q;
    u = l = p = q = n;
    for (int k = i + 1; k < n; k++)
    {
        if (n == u && a[i] < a[k])
            u = k;
        if (a[i] > a[k] && n == l)
            l = k;
    }
    for (int k = j + 1; k < n; k++)
    {
        if (n == p && b[j] < b[k])
            p = k;
        if (b[j] > b[k] && n == q)
            q = k;
    }
    // cout << i << " " << j << " " << p << " " << q << " " << l << " " << u << endl;
    if (func(u, p) == 0 || func(l, q) == 0)
        return 0;
    return 1;
}
int main()
{
    // int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a[n] = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    // cout<<a[1]<<" "<<b[3];
    b[n] = INT_MIN;
    if (func(0, 0) == 0)
        cout << "NO";
    else
    {
        cout << "YES";
    }
}