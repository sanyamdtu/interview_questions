class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &a)
    {
        int n = a.size();
        int dp = 0, ans = 0;
        for (int i = 2; i < n; i++)
        {
            if (a[i] - a[i - 1] == a[i - 1] - a[i - 2])
            {
                dp++;
                ans += dp;
            }
            else
                dp = 0;
        }
        return ans;
    }
};