#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll temp = gcd(a, b);
        if (c % temp == 0)
        {
            cout << "Case " << i << ":"
                 << " Yes"
                 << "\n";
        }
        else
        {
            cout << "Case " << i << ":"
                 << " No"
                 << "\n";
        }
    }
}