
typedef long long ll;
class Solution
{

    // 1 3 4 5 7
public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        ll c = 0;
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1, k = n - 1; j < k;)
            {
                int s = arr[i] + arr[j] + arr[k];
                if (s >= sum)
                {
                    k--;
                }
                else
                {
                    c += (k - j);
                    j++;
                }
            }
        }
        return c;
    }
};
