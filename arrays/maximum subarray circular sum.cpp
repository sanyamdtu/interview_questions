class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &arr)
    {
        int maxi = INT_MIN, mini = INT_MAX, curr = 0, n = arr.size(), sum = 0;
        for (auto i : arr)
        {
            sum += i;
            curr += i;
            maxi = max(maxi, curr);
            if (curr < 0)
                curr = 0;
        }
        curr = 0;
        for (auto i : arr)
        {
            curr += i;
            mini = min(mini, curr);
            if (curr > 0)
                curr = 0;
        }
        if (sum == mini)
            return maxi;
        return max(maxi, sum - mini);
    }
};