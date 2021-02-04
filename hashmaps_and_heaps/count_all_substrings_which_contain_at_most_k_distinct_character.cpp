#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int i = 0, j = 0, n = s.length(), c = 0, k, ans = 0;
    cin >> k;
    unordered_map<char, int> m;
    while (j < n)
    {
        m[s[j]]++;
        if (m[s[j]] == 1)
            c++;
        while (c > k)
        {
            m[s[i]]--;
            if (m[s[i]] == 0)
                c--;
            i++;
        }
        ans += j - i + 1;
        j++;
    }
    cout << ans;
}