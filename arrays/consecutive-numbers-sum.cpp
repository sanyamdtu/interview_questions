class Solution
{
public:
    int consecutiveNumbersSum(int n)
    {
        long long ans = 1, p = 4 * (long long)n;
        for (long long i = 2; i <= sqrt(p); i++)
        {
            long long temp = (i * (i - 1)) / 2;
            if ((n - temp) > 0 && (n - temp) % i == 0)
                ans++;
        }
        return ans;
    }
};