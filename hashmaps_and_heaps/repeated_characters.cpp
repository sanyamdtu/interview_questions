#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string p;
        cin >> p;
        map<char, int> m;
        for (auto i : p)
        {
            m[i]++;
        }
        multiset<pair<int, char>> s;
        for (auto i : m)
        {
            s.insert({-i.second, i.first});
        }
        int f = 1;
        auto temp = *(s.begin());
        temp.first++;
        s.erase(s.begin());
        while (!s.empty())
        {
            auto a = *(s.begin());
            s.erase(s.begin());
            a.first++;
            if (temp.first != 0)
                s.insert(temp);
            temp = a;
        }
        if (temp.first != 0)
            f = 0;
        if (f == 0)
            cout << 0;
        else
            cout << 1;
        cout << endl;
    }
    return 0;
}