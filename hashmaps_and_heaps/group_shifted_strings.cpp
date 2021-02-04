#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> arr = {"acd", "dfg", "wyz", "yab", "mop", "bdfh", "a", "x", "moqs"};
    unordered_map<string, vector<string>> m;
    for (auto i : arr)
    {
        string a = "";
        for (int j = 1; j < i.length(); j++)
        {
            a += to_string(i[j] - i[j - 1]);
        }
        m[a].push_back(i);
    }
}