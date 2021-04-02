#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long arr[n];
        long long sum = 0;
        long long ans = INT64_MIN, curr = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
            ans = max(ans, arr[i]);
        }
        if (k >= 2)
        {
            long long temp[2 * n];
            for (int i = 0, c = 0; i < 2 * n; i++, c = (c + 1) % n)
            {
                temp[i] = arr[c];
            }
            for (int i = 0; i < 2 * n; i++)
            {
                curr += temp[i];
                ans = max(curr, ans);
                if (curr < 0)
                    curr = 0;
            }
            if (sum > 0)
                ans += (k - 2) * sum;
        }
        else
        {
            if (sum > 0)
                ans = sum;
        }

        cout << ans << endl;
    }
}