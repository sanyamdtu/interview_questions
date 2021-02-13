typedef long long ll;

class Solution
{
public:
    int minEatingSpeed(vector<int> &arr, int h)
    {
        ll n = arr.size(), lo = 1, hi = 1, ans = INT_MAX;
        for (int i = 0; i < n; i++)
            hi = max(hi, (ll)arr[i]);
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            ll d = 0;
            for (int i = 0; i < n; i++)
            {
                d += (arr[i] + mid - 1) / mid;
            }
            if (d <= h)
            {
                ans = min(ans, mid);
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};