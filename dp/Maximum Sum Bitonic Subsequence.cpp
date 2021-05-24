int maxSumBS(int arr[], int n)
{
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                a[i] = max(a[i], arr[i] + a[j]);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j])
                b[i] = max(b[i], arr[i] + b[j]);
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, a[i] + b[i] - arr[i]);
    }
    return ans;
}
