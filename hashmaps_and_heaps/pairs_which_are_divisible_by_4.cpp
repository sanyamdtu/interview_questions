int count4Divisibiles(int arr[], int n)
{
    unordered_map<int, int> m;
    int ans = 0;
    int k = 4;
    for (int i = 0; i < n; i++)
    {
        int d = (arr[i]) % k;
        if (d < 0)
            d = k - d;
        int p = 0;
        if (d != 0)
            p = k - d;
        ans += m[p];
        m[d]++;
    }
    return ans;
}
