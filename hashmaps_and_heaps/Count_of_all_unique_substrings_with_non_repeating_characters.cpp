#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length(), i = 0, j = 0, c = 0, ans = 0;
    unordered_map<char, int> m;
    while (j < n)
    {
        m[s[j]]++;
        while (m[s[j]] > 1)
        {
            m[s[i]]--;
            i++;
        }
        ans += j - i + 1;
        j++;
    }
    cout << ans;
}