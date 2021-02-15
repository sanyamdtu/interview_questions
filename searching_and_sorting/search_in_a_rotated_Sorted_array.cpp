class Solution
{
public:
    int find(vector<int> &arr, int lo, int hi, int k)
    {
        int n = arr.size(), ans = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] < k)
            {
                lo = mid + 1;
            }
            else if (arr[mid] == k)
            {
                return mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int> &arr, int k)
    {
        int n = arr.size();
        int lo = 0, hi = n - 1, ans = n - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] > arr[n - 1])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
                ans = min(ans, mid);
            }
        }
        cout << ans;
        if (arr[n - 1] < k)
        {
            return find(arr, 0, ans - 1, k);
        }
        else
        {
            return find(arr, ans, n - 1, k);
        }
    }
};