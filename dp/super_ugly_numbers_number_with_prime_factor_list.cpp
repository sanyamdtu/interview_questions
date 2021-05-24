#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 50, k;
    int arr[] = {2, 3, 5};
    k = sizeof(arr) / sizeof(arr[0]);
    vector<int> dp;
    dp.push_back(1);
    int a[k];
    memset(a, 0, sizeof(a));
    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = 0; j < k; j++)
        {
            mini = min(mini, dp[a[j]] * arr[j]);
        }
        dp.push_back(mini);
        for (int j = 0; j < k; j++)
        {
            if (dp.back() == dp[a[j]] * arr[j])
                a[j]++;
        }
    }
    cout << dp.back();
}