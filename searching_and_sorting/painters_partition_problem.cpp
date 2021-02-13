typedef long long ll;
int Solution::paint(int a, int b, vector<int> &arr)
{
    ll hi = 0, lo = 0, n = arr.size(), mid, ans = INT_MAX, mod = 10000003;
    for (auto i : arr)
    {
        hi = (hi + i);
        lo = max(lo, (ll)i);
    }
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        ll s = 0, c = 0;
        for (int i = 0; i < n;)
        {
            if (s + arr[i] > mid)
            {
                c++;
                s = 0;
            }
            else
                s += arr[i++];
        }
        if (s > 0)
            c++;
        if (c <= a)
        {
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return (ans * (ll)b) % mod;
}
