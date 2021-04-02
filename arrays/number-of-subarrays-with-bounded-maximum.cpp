class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &arr, int l, int r)
    {
        long long ans = 0, i = 0, j = 0, temp = 0, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > r)
            {
                temp = 0;
                j = i + 1;
            }
            else if (arr[i] >= l)
            {
                temp = i - j + 1;
                ans += temp;
            }
            else
            {
                ans += temp;
            }
        }
        return ans;
    }
};