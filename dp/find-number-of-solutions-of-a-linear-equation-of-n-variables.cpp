#include <bits/stdc++.h>
using namespace std;
int n;
int arr[] = {2, 2, 3};
int rhs = 4;

int main()
{
    n = sizeof(arr) / sizeof(arr[0]);
    int dp[rhs + 2][n];
    memset(dp, 0, sizeof(dp));
    int f = 0;
    cout << arr[0] << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= rhs; j += arr[i])
        {
            dp[i][j] = 1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= rhs; j++)
        {

            dp[j][i] += dp[j][i - 1];
            if (j - arr[i] >= 0)
                dp[j][i] += dp[j - arr[i]][i - 1];
        }
    }
    cout << dp[rhs][n - 1];
}