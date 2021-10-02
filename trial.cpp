#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n), qu(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> qu[i];
    }
    for (auto q : qu)
    {
        ll lo = 1, hi = 1000000000000000000, ans = -1;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            auto a = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
            if (mid - a == q)
            {
                ans = mid;
                break;
            }
            else if ((mid - a) < q)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        cout << ans << endl;
    }
}
