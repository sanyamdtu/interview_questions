#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 7;
    int arr[] = {10, 12, 12, 10, 10, 11, 10};
    int ans = 1;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int maxi = arr[i], mini = arr[i];
        m[arr[i]]++;
        for (int j = i + 1; j < n; j++)
        {
            m[arr[j]]++;
            if (m[arr[j]] != 1)
                break;
            maxi = max(maxi, arr[j]);
            mini = min(mini, arr[j]);
            if (maxi - mini == j - i)
                ans = max(ans, j - i + 1);
        }
    }
    cout << ans;
}