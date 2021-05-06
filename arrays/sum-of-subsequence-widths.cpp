typedef long long ll;
class Solution
{
public:
    long long mod;
    int sumSubseqWidths(vector<int> &a)
    {

        mod = 1000 * 1000 * 1000;
        mod += 7;
        int n = a.size();
        int arr[n];
        for (int i = 0; i < n; i++)
            arr[i] = a[i];
        sort(arr, arr + n);
        ll ans = 0;
        ll c = 1;
        for (int i = 0; i < n; i++)
        {
            ll a = (arr[i] * c) % mod;
            ll b = (c * arr[n - 1 - i]) % mod;
            ans = (mod + ans + a - b) % mod;
            c = (c * 2) % mod;
        }
        // cout<<"pop";
        return ans;
    }
};