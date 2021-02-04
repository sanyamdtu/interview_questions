#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        unordered_map<int, int> m;
        int j = 0;
        int ans = 0;
        for (int i = 0; j < n; j++)
        {
            m[arr[j]]++;
            while (m[arr[j]] != 1)
            {
                m[arr[i]]--;
                i++;
            }
            int l = j - i + 1;
            ans += (l * (l + 1)) / 2;
        }
        cout << ans << endl;
    }
}