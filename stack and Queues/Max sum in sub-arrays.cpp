
typedef long long ll;
class Solution
{
public:
    long long pairWithMaxSum(long long arr[], long long n)
    {
        long long ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, arr[i] + arr[i + 1]);
        }
        return ans;
    }
};
