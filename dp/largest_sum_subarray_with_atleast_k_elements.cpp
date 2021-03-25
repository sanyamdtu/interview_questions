
typedef long long ll;
long long int maxSumWithK(long long int arr[], long long int n, long long int k)
{
    ll dp[n], temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = max(temp + arr[i], arr[i]);
        dp[i] = temp;
    }
    ll sum[n];
    ll p = 0;
    for (int i = 0, j = 0; j < n; j++)
    {
        p += arr[j];
        if (j - i + 1 == k)
        {
            sum[i] = p;
            p -= arr[i];
            i++;
        }
    }
    ll ans = INT64_MIN;
    for (int i = 0; i <= n - k; i++)
    {
        ll temp = sum[i];
        temp += max((ll)0, dp[i] - arr[i]);
        ans = max(ans, temp);
    }
    return ans;
}