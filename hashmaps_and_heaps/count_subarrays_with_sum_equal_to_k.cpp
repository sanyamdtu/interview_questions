class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        unordered_map<int, int> m;
        int n = arr.size();
        m[0] = 1;
        int ans = 0;
        for (int i = 1; i < n; i++)
            arr[i] += arr[i - 1];
        for (int j = 0; j < n; j++)
        {
            ans += m[arr[j] - k];
            m[arr[j]]++;
        }
        return ans;
    }
};