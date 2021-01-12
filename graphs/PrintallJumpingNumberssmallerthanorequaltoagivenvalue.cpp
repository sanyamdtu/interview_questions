#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a;
    cin >> a;
    ll ans = 0;
    string p = to_string(a);
    for (ll j = 1; j <= 9; j++)
    {
        ll b = j;
        if (b <= a)
            ans = max(ans, b);
        for (ll i = 1; i < p.length(); i++)
        {
            if (b % 10 == 9)
            {
                b = b * 10 + 8;
            }
            else
            {
                b = b * 10 + (b % 10) + 1;
            }
            if (b <= a)
                ans = max(ans, b);
        }
        }
    cout << ans;
}