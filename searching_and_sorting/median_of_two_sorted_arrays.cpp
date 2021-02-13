class Solution
{
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b)
    {
        int n = a.size(), m = b.size();
        if (n == 0)
        {
            if (m % 2 == 0)
                return (1.0 * b[(m / 2) - 1] + b[(m / 2)] * 1.0) / 2;
            else
                return 1.0 * b[(m / 2)];
        }
        if (m == 0)
        {
            if (n % 2 == 0)
                return (1.0 * a[(n / 2) - 1] + a[(n / 2)] * 1.0) / 2;
            else
                return 1.0 * a[(n / 2)];
        }
        int mid1, mid2, t = n + m;
        int h = (t + 1) / 2, lo = 0, hi = a.size();
        while (lo <= hi)
        {
            mid1 = lo + (hi - lo) / 2;
            mid2 = h - mid1;
            if (mid2 < 0)
            {
                hi = mid1 - 1;
                continue;
            }
            if (mid2 > m)
            {
                lo = mid1 + 1;
                continue;
            }
            if (mid2 != 0 && mid1 < n && a[mid1] < b[mid2 - 1])
                lo = mid1 + 1;
            else if (mid1 != 0 && mid2 < m && a[mid1 - 1] > b[mid2])
                hi = mid1 - 1;
            else
                break;
        }
        int l = INT_MIN, r = INT_MIN;
        if ((m + n) % 2 == 0)
        {
            if (mid2 == 0)
                l = a[mid1 - 1];
            else if (mid1 == 0)
                l = b[mid2 - 1];
            else
                l = max(a[mid1 - 1], b[mid2 - 1]);
            if (mid2 == m)
                r = a[mid1];
            else if (mid1 == n)
                r = b[mid2];
            else
                r = min(a[mid1], b[mid2]);
            return (l * 1.0 + r * 1.0) / 2;
        }
        else
        {
            if (mid2 == 0)
                l = a[mid1 - 1];
            else if (mid1 == 0)
                l = b[mid2 - 1];
            else
                l = max(a[mid1 - 1], b[mid2 - 1]);
            return l * 1.0;
        }
        return 1.0;
    }
};