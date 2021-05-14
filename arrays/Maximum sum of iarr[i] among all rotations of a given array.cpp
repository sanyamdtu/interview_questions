int max_sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    long long ans = 0, res = 0;
    for (int i = 0; i < n; i++)
        ans += arr[i] * i;
    for (int i = 0; i < n; i++)
    {
        ans = ans - sum + (arr[i] * (n));
        res = max(ans, res);
    }
    return res;
}