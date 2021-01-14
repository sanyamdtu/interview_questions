class Solution
{
public:
    int leastBricks(vector<vector<int>> &arr)
    {
        unordered_map<int, int> m;
        for (auto p : arr)
        {
            int x = 0;
            for (auto i : p)
            {
                x += i;
                m[x]++;
            }
            m[x]--;
        }
        int ans = 0;
        for (auto i : m)
        {
            ans = max(ans, i.second);
        }
        return arr.size() - ans;
    }
};