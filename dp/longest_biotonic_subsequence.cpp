
class Solution
{
public:
    int LongestBitonicSequence(vector<int> arr)
    {
        int n = arr.size();
        int f[n], b[n];
        for (int i = 0; i < n; i++)
            f[i] = b[i] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[i] > arr[j])
                    f[i] = max(f[i], f[j] + 1);
            }
        }
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[i] > arr[j])
                    b[n - i - 1] = max(b[n - 1 - i], b[n - j - 1] + 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, f[i] + b[i] - 1);
        }
        return ans;
    }
};
