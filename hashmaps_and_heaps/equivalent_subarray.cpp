#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    unordered_map<ll, ll> m;
    ll i = 0, j = 0, ans = 0;
    while (j < n)
    {
        m[arr[j]]++;
        j++;
    }
    ll k = m.size();
    m.clear();
    j = 0;
    ll c = 0, p = 0;
    while (j < n)
    {
        m[arr[j]]++;
        if (m[arr[j]] == 1)
            c++;
        while (c > k)
        {
            m[arr[i]]--;
            if (m[arr[i]] == 0)
                c--;
            p = 0;
            i++;
        }
        while (m[arr[i]] > 1)
        {
            m[arr[i]]--;
            i++;
            p++;
        }
        if (c == k)
            ans += p + 1;
        j++;
    }
    cout << ans << endl;
}