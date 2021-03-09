#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> gcd(ll a, ll b)
{
    if (b == 0)
    {
        vector<ll> v{1, 0, a};
        return v;
    }
    auto v = gcd(b, a % b);
    vector<ll> p{v[1], v[0] - ((a / b) * v[1]), v[2]};
    return p;
}
int main()
{
    ll a, b;
    cin >> a >> b;
    for (auto i : gcd(a, b))
    {
        cout << i << " ";
    }
}