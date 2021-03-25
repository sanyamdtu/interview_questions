#include <bits/stdc++.h>
using namespace std;
int main()
{
    int freq[] = {34, 8, 50};
    int key[] = {10, 12, 20};
    int n = sizeof(key) / sizeof(key[0]);
    int sum[100][100];
    for (int i = 1; i < n; i++)
        freq[i] += freq[i - 1];
    for (int i = 0; i < n; i++)
        sum[0][i] = freq[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            sum[i + 1][j] = freq[j] - freq[i];

    int dp[100][100];
    memset(dp, 0, sizeof(dp));
    for (int gap = 0; gap < n; gap++)
    {
        for (int l = 0; l < n - gap; l++)
        {
            int r = l + gap;
            if (gap == 0)
                dp[l][r] = sum[l][r];
            else
            {
                dp[l][r] = INT_MAX;
                for (int k = l; k <= r; k++)
                {
                    int lp = 0, rp = dp[k + 1][r];
                    if (k != 0)
                        lp = dp[l][k - 1];
                    dp[l][r] = min(dp[l][r], lp + rp + sum[l][r]);
                }
            }
        }
    }
    cout << dp[0][n - 1];
}