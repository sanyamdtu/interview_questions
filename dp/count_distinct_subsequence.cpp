#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    string s;
    cin >> s;
    unordered_map<char, long long> m, ans;
    m[s[0]] = 1;
    ans[s[0]] = 2;
    for (int i = 1; i < s.length(); i++)
    {
        ans[s[i]] = ((2 * ans[s[i - 1]]) % mod - m[s[i]] + mod) % mod;
        m[s[i]] = ans[s[i - 1]];
    }
    cout << ans[s.back()] - 1;
}