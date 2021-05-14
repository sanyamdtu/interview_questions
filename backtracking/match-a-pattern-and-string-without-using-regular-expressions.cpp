#include <bits/stdc++.h>
using namespace std;
string s, t;
int n, k;
bool func(unordered_map<char, string> &m, int i, int j)
{
    if (i == n || j == k)
        return (i == n && j == k);
    if (m.find(t[j]) != m.end())
    {
        string a = "";
        for (int k = i; k < n; k++)
        {
            a += s[k];
            if (m[t[j]] == a)
                if (func(m, k + 1, j + 1))
                    return true;
        }
    }
    else
    {
        string a = "";
        for (int k = i; k < n; k++)
        {
            a += s[k];
            m[t[j]] = a;
            if (func(m, k + 1, j + 1))
                return true;
            m.erase(m.find(t[j]));
        }
    }
    return false;
}
int main()
{

    cin >> s >> t;
    n = s.length(), k = t.length();
    unordered_map<char, string> m;
    if (func(m, 0, 0))
        cout << "Yes";
    else
        cout << "No";
}