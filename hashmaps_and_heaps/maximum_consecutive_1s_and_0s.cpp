class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &arr)
    {
        int ans = 0, f = 0;
        for (auto i : arr)
        {
            if (i == 1)
                f++;
            else
                f = 0;
            ans = max(ans, f);
        }
        return ans;
    }
};