class Solution
{
public:
    int numTimesAllBlue(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = 1, ans = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, arr[i]);
            if (maxi == i + 1)
                ans++;
        }
        return ans;
    }
};