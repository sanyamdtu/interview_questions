#include <bits/stdc++.h>
using namespace std;
int main()
{
    string arr;
    cin >> arr;
    int i = 0, j = 0, n = arr.length(), ans = 0;
    unordered_map<char, int> m;
    while (j < n)
    {
        m[arr[j]]++;
        while (m[arr[j]] > 1)
        {
            m[arr[i]]--;
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    cout << ans;
}