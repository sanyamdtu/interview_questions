class Solution
{
public:
    int numRabbits(vector<int> &arr)
    {
        unordered_map<int, int> m;
        int ans = 0;
        for (auto i : arr)
            m[i]++;
        for (auto j : m)
            ans += ((j.second + j.first) / (j.first + 1)) * (j.first + 1);
        return ans;
    }
};