#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod;
ll pw(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll temp = 1;
    if (b % 2 == 1)
        temp = a;
    return (temp * ((pw(a, b / 2) * pw(a, b / 2)) % mod)) % mod;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n >> mod;
        if (n >= mod)
        {
            cout << 0 << endl;
        }
        else
        {
            ll ans = mod - 1;
            for (int i = n + 1; i <= mod - 1; i++)
            {
                ans = (ans * pw(i, mod - 2)) % mod;
            }
            cout << ans << endl;
        }
    }
}