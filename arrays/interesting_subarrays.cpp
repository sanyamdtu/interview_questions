#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin >> t;
    for (int l = 1; l <= t; l++)
    {
        // cout << l << endl;
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int f = 1;
        int i = 0;
        if (n > 1)
        {
            for (; i < n - 1; i++)
            {
                if (abs(arr[i] - arr[i + 1]) >= 2)
                {
                    f = 0;
                    break;
                }
            }
        }

        if (f == 0)
            cout << "YES" << endl
                 << i + 1 << " " << i + 2 << endl;
        else
            cout << "NO" << endl;
    }
}