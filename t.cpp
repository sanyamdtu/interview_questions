#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
int dp[100][3000];
int solve(vector<int> &arr, int i, int num)
{
    if (num < 0)
        return 0;
    if (num == 0)
        return 1;
    if (i == arr.size())
        return 0;
    if (dp[i][num] != -1)
        return dp[i][num];
    long long ans = (solve(arr, i + 1, num) + solve(arr, i, num - arr[i])) % MOD;
    return dp[i][num] = ans;
}
int main()
{
    int num;
    cin >> num;
    vector<int> arr;
    for (int i = 1; i * i <= 2500; i++)
    {
        arr.push_back(i * i);
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(arr, 0, num);
}
