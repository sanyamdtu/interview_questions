#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long arr[n];
    long long size = ceil(sqrt(n));
    long long m = ceil(n / size);
    cout << m;
    long long box[m];
    for (long long i = 0; i < m; i++)
    {
        box[i] = INT_MAX;
    }
    long long i = 0;
    while (i < n)
    {
        box[i / size] = min(arr[i], box[i / size]);
        i++;
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long q;
    cin >> q;
    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        long long ans = INT_MAX;
        while (l <= r)
        {
            if ((l % size == 0) && (l + size - 1 <= r))
            {
                ans = min(ans, box[l / size]);
                l += size;
            }
            else
            {
                ans = min(ans, arr[l]);
                ++l;
            }
        }
        cout << ans << endl;
    }
}