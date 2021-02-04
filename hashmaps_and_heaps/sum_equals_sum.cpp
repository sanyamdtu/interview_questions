
typedef long long ll;
class Solution
{
public:
    int findPairs(long long arr[], long long n)
    {
        unordered_map<ll, ll> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (m[arr[i] + arr[j]] != 0 && m[arr[i] + arr[j]] != i + 1)
                    return 1;
                m[arr[i] + arr[j]] = i + 1;
            }
        }
        return 0;
    }
};
