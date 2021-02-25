class Solution
{
public:
    int search(vector<int> &arr, int k)
    {
        int n = arr.size();
        int lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == k)
                return mid;
            if (arr[lo] <= arr[mid])
            {
                if (arr[lo] <= k && k <= arr[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            else
            {
                if (arr[mid] <= k && k <= arr[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return -1;
    }
};