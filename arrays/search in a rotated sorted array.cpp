class Solution
{
public:
    int search(vector<int> &arr, int k)
    {
        int n = arr.size();
        int lo = 0, hi = n - 1, ans = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] < arr[0])
                hi = mid - 1;
            else
            {
                ans = max(ans, mid);
                lo = mid + 1;
            }
        }
        if (k < arr[0])
        {
            lo = ans + 1;
            hi = n - 1;
        }
        else
        {
            lo = 0;
            hi = ans;
        }
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] > k)
                hi = mid - 1;
            else if (arr[mid] < k)
                lo = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};