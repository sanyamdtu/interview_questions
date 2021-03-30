class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        int maxi[n], mini[n], c = INT_MAX, d = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            d = max(d, arr[i]);
            maxi[i] = d;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            c = min(c, arr[i]);
            mini[i] = c;
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (mini[i + 1] > maxi[i])
                ans++;
        }
        return ans + 1;
    }
};