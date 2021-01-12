#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1000][10];
int func(int i, int arr[], int k)
{
    if (i >= n)
        return 0;
    if (dp[i][k] != INT_MIN)
        return dp[i][k];
    int a = k * arr[i] + func(i + 1, arr, 1);
    int b = k * arr[i] + func(i + 2, arr, 2);
    int c = k * arr[i] + func(i + 3, arr, 3);
    return dp[i][k] = max(a, max(b, c));
}
int main()
{

    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < 10; j++)
            dp[i][j] = INT_MIN;
    }
    cout << max(func(0, arr, 1), max(func(1, arr, 2), func(2, arr, 3)));
    return 0;
}