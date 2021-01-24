#include <bits/stdc++.h>
using namespace std;
int main()
{

    int arr[] = {10, 12, 12, 10, 10, 11, 10};
    int ans = 1;
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> m;
        m[arr[i]]++;
        int maxi = arr[i], mini = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (m[arr[j]] != 0)
                break;
            m[arr[j]]++;
            maxi = max(maxi, arr[j]);
            mini = min(mini, arr[j]);
            if (maxi - mini == j - i)
                ans = max(ans, j - i + 1);
        }
    }
    cout << ans;
}