#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long arr[n];
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for (long long i = 0; i < n; i++)
        {
            dp[i + 1] = arr[i];
            if (i + 1 - arr[i] >= 0)
                dp[i + 1 - arr[i]] -= arr[i];
        }

        for (long long i = n - 1; i > 0; i--)
        {
            dp[i] += dp[i + 1];
        }
        for (long long i = 1; i <= n; i++)
        {
            if (dp[i] >= 1)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}