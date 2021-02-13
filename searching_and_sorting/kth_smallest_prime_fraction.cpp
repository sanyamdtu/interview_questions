class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        double lo = 0.0, hi = 1.0, mid, n = arr.size();
        while (1)
        {
            mid = lo + (hi - lo) / 2;
            int i = 0, j = n - 2, c = 0, N = 0, D = 1;
            while (i < n - 1 && j >= 0)
            {
                while (j >= 0 && arr[i] > mid * arr[n - 1 - j])
                    j--;
                if (j >= 0)
                {
                    if (N * arr[n - 1 - j] < D * arr[i])
                    {
                        N = arr[i];
                        D = arr[n - 1 - j];
                    }
                    c += j + 1;
                    i++;
                }
            }
            if (c == k)
                return {N, D};
            else if (c > k)
                hi = mid;
            else
                lo = mid;
        }
        return {1, 0};
    }
};