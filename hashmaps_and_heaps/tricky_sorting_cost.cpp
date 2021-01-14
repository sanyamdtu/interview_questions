
class Solution
{
public:
    int sortingCost(int n, int arr[])
    {
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]] = m[arr[i] - 1] + 1;
        }
        int ans = 0;
        for (auto i : m)
        {
            ans = max(ans, i.second);
        }
        return n - ans;
    }
};