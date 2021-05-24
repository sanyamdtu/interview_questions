#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 10;
    int dp[100];
    memset(dp, 0, sizeof(dp));
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] = max(dp[i], j * dp[i - j]);
            dp[i] = max(dp[i], j * (i - j));
        }
    }
}