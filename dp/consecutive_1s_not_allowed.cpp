
class Solution
{
public:
    // #define ll long long
    int mod;
    ll countStrings(int n)
    {
        if (n == 1)
            return 2;
        mod = 1000 * 1000 * 1000;
        mod += 7;
        int in = 1, en = 1;
        for (int i = 1; i < n; i++)
        {
            int temp = in;
            in = (in + en) % mod;
            en = temp;
        }
        return (in + en) % mod;
    }
};
