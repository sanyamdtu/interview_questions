class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        int n = arr.size();
        long long curr = 1, maxi = INT_MIN;
        for (auto i : arr)
        {
            curr = curr * i;
            maxi = max(maxi, curr);
            if (i == 0)
            {
                curr = 1;
            }
        }
        curr = 1;
        reverse(arr.begin(), arr.end());
        for (auto i : arr)
        {
            curr = curr * i;
            maxi = max(maxi, curr);
            if (i == 0)
            {
                curr = 1;
            }
        }
        return maxi;
    }
};