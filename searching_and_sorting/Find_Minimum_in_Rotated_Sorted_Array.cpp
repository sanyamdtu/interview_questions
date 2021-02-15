class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int n = arr.size();
        int lo = 0, hi = n - 1, ans = n - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] > arr[n - 1])
                lo = mid + 1;
            else
            {
                ans = min(ans, mid);
                hi = mid - 1;
            }
        }
        return arr[ans];
    }
};