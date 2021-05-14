typedef long long ll;
class Solution
{
public:
    int equilibriumPoint(long long arr[], int n)
    {
        ll sum = 0, p = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        for (int i = 0; i < n; i++)
        {
            if (sum - arr[i] - p == p)
                return i + 1;
            p += arr[i];
        }
        return -1;
    }
};
