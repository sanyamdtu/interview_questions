typedef long long ll;
void merge(ll arr[], ll n, ll s, ll mid, ll e, ll &k)
{
    ll t = e - s + 1, i = s, j = mid + 1, c = 0;
    ll temp[t];
    while (i < mid + 1 && j <= e)
    {
        if (arr[i] <= arr[j])
            temp[c++] = arr[i++];
        else
        {
            k += mid - i + 1;
            temp[c++] = arr[j++];
        }
    }
    while (i < mid + 1)
        temp[c++] = arr[i++];
    while (j <= e)
        temp[c++] = arr[j++];
    c = 0;
    i = s;
    while (c < t)
        arr[i++] = temp[c++];
}
void mergesort(ll arr[], ll n, ll s, ll e, ll &c)
{
    if (s >= e)
        return;
    ll mid = s + (e - s) / 2;
    mergesort(arr, n, s, mid, c);
    mergesort(arr, n, mid + 1, e, c);
    merge(arr, n, s, mid, e, c);
}
long long int inversionCount(long long arr[], long long n)
{
    ll c = 0;
    mergesort(arr, n, 0, n - 1, c);
    return c;
}