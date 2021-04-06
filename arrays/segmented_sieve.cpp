#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long arr[300005];
long long s[300005];
int main()
{
    long long t;
    cin >> t;
    vector<long long> p;
    for (long long i = 0; i < 300005; i++)
    {
        s[i] = 1;
    }
    for (long long i = 2; i <= 300000; i++)
    {
        if (s[i] == 1)
        {
            p.push_back(i);
            for (long long j = 2 * i; j <= 300000; j += i)
            {
                s[j] = 0;
            }
        }
    }
    while (t--)
    {
        ll m, n;
        cin >> m >> n;
        for (long long i = 0; i < 300005; i++)
        {
            arr[i] = 1;
        }
        for (auto i : p)
        {
            ll temp = ((m + i - 1) / i) * (i);
            for (long long j = temp; j <= n; j += i)
            {
                if (i != j)
                    arr[j - m] = 0;
            }
        }
        ll ans = 0;
        for (ll i = m; i <= n; i++)
        {
            if (i != 1 && arr[i - m] == 1)
                cout << i << endl;
        }
        cout << endl;
    }
}