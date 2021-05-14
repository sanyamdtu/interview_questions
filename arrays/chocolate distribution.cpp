long long findMinDiff(vector<long long> arr, long long n, long long m)
{
    sort(arr.begin(), arr.end());
    ll ans = INT_MAX;
    for (int i = 0, j = 0; j < n; j++)
    {
        if (j - i + 1 == m)
        {
            ans = min(ans, arr[j] - arr[i]);
            i++;
        }
    }
    return ans;
}