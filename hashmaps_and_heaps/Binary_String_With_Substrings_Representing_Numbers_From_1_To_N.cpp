#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int f = 1;
    for (int i = k; i >= 1; i--)
    {
        string p = bitset<32>(i).to_string();
        if (s.find(p.substr(p.find("1"))) == string::npos)
        {
            f = 0;
            break;
        }
    }
    if (f == 1)
        cout << "true";
    else
    {
        cout << "false";
    }
}