class Solution
{
public:
    int maxSubArray(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return arr[0];
        int curr = 0, ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            curr += arr[i];
            ans = max(ans, curr);
            if (curr < 0)
                curr = 0;
        }
        return ans;
    }
};