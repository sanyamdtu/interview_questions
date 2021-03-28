#include <bits/stdc++.h>
using namespace std;
#define n 100001
int dp[n];
int karr[n], kp1[n];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q, k;
        cin >> q >> k;
        memset(dp, 0, sizeof(dp));
        int s[q], e[q];
        for (int i = 0; i < q; i++)
        {
            cin >> s[i] >> e[i];
            s[i]--;
            e[i]--;
            dp[s[i]]++;
            dp[e[i] + 1]--;
        }
        for (int i = 1; i < n + 1; i++)
        {
            dp[i] += dp[i - 1];
        }
        memset(karr, 0, sizeof(karr));
        memset(kp1, 0, sizeof(kp1));
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == k)
                karr[i] = 1;
            if (dp[i] == k + 1)
                kp1[i] = 1;
            if (i != 0)
            {
                kp1[i] += kp1[i - 1];
                karr[i] += karr[i - 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < q; i++)
        {
            int kf = 0, kp1f = 0;
            if (s[i] == 0)
            {
                kf = karr[e[i]];
                kp1f = kp1[e[i]];
            }
            else
            {
                kf = karr[e[i]] - karr[s[i] - 1];
                kp1f = kp1[e[i]] - kp1[s[i] - 1];
            }
            ans = max(ans, karr[n - 1] - kf + kp1f);
        }
        cout << ans << endl;
    }
}