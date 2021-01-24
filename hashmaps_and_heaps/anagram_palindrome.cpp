#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        unordered_map<char, int> m;
        for (auto i : s)
            m[i]++;
        int f = 0;
        for (auto i : m)
        {
            if (i.second % 2 == 1)
                f++;
        }
        if (f >= 2)
            cout << "No";
        else
            cout << "Yes";
        cout << endl;
    }
}