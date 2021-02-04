#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    unordered_map<char, int> m;
    int j = 0, i = 0, n = s.length(), ans = -1, c = 0;
    while (j < n)
    {
        m[s[j]]++;
        if (m[s[j]] == 1)
            c++;
        while (c > k)
        {
            m[s[i]]--;
            if (m[s[i++]] == 0)
                c--;
        }
        if (c == k)
            ans = max(ans, j - i + 1);
        j++;
    }
    cout << ans << endl;
    return 0;
}