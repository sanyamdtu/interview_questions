#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    unordered_map<string, int> m;
    m["0#0"] = 1;
    int a[n], b[n], c[n];
    if (s[0] == '0')
    {
        a[0] = 1;
        b[0] = 0;
        c[0] = 0;
    }
    else if (s[0] == '1')
    {
        a[0] = 0;
        b[0] = 1;
        c[0] = 0;
    }
    else
    {
        a[0] = 0;
        b[0] = 0;
        c[0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1];
        b[i] = b[i - 1];
        c[i] = c[i - 1];
        if (s[i] == '0')
            a[i]++;
        else if (s[i] == '1')
            b[i]++;
        else
            c[i]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string p = "";
        p += to_string((a[i] - b[i]));
        p += "#";
        p += to_string((b[i] - c[i]));
        ans += m[p];
        m[p]++;
    }
    cout << ans;
}