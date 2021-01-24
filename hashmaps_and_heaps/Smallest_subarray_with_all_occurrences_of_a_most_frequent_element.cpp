#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    unordered_map<int, pair<int, int>> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) == m.end())
            m[arr[i]] = {i, i};
        m[arr[i]].second = i;
    }
    int ans = INT_MAX;
    for (auto i : m)
        ans = min(ans, i.second.second - i.second.first + 1);
    cout << ans;
}