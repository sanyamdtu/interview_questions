#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll l, r;
    cin >> l >> r;
    cout << "YES" << endl;
    ll a = l;
    for (ll i = 1; i <= (r - l + 1) / 2; i++)
    {
        cout << a << " " << a + 1 << endl;
        a += 2;
    }
}