
typedef long long ll;
class Solution
{
public:
    vector<int> m[10];
    long long getCount(int n)
    {
        if (n == 1)
            return 10;
        m[0] = {0, 8};
        m[1] = {2, 4, 1};
        m[2] = {1, 3, 5, 2};
        m[3] = {2, 6, 3};
        m[4] = {1, 5, 7, 4};
        m[5] = {2, 4, 6, 8, 5};
        m[6] = {3, 5, 9, 6};
        m[7] = {4, 8, 7};
        m[8] = {5, 7, 9, 0, 8};
        m[9] = {6, 8, 9};
        ll dp[10][2];
        for (int i = 0; i < 10; i++)
            dp[i][0] = dp[i][1] = 1;
        int f = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                ll ans = 0;
                for (auto k : m[j])
                    ans += dp[k][1 - f];
                dp[j][f] = ans;
            }
            f = 1 - f;
        }
        ll ans = 0;
        for (int i = 0; i <= 9; i++)
            ans += dp[i][1 - f];
        return ans;
    }
};
