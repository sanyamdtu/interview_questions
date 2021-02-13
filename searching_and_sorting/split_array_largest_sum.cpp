class Solution
{
public:
    int splitArray(vector<int> &arr, int k)
    {
        int hi = 0, lo = 0, n = arr.size(), ans = INT_MAX;
        for (auto i : arr)
        {
            hi += i;
            lo = max(lo, i);
        }
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int s = 0, c = 0;
            for (int i = 0; i < arr.size();)
            {
                if (s + arr[i] > mid)
                {
                    s = 0;
                    c++;
                }
                else
                    s += arr[i++];
            }
            if (s > 0)
                c++;
            if (c <= k)
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