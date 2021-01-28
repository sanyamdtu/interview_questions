
int minDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int j = 0;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (i - j + 1 == k)
        {
            ans = min(ans, arr[i] - arr[j]);
            j++;
        }
    }
    return ans;
}