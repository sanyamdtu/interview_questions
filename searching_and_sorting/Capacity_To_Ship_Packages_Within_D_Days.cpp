class Solution
{
public:
    int shipWithinDays(vector<int> &arr, int d)
    {
        int hi = 0, lo = INT_MIN;
        for (auto i : arr)
        {
            lo = max(lo, i);
            hi += i;
        }
        int ans = INT_MAX;
        int mid = 0;
        while (lo <= hi)
        {
            mid = lo + ((hi - lo) / 2);
            int days = 0, s = 0;
            for (int i = 0; i < arr.size();)
            {
                if (s + arr[i] > mid)
                {
                    days++;
                    s = 0;
                }
                else
                    s += arr[i++];
            }
            if (s > 0)
                days++;
            if (days <= d)
            {
                ans = min(mid, ans);
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};