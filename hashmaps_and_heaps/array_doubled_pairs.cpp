class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> m;
        for (auto i : arr)
            m[i]++;
        for (auto i : arr)
        {
            if (m[i] >= 1)
            {
                m[i]--;
                if (i >= 0)
                    if (m[i * 2] != 0)
                        m[i * 2]--;
                    else
                        return false;
                else
                {
                    if (i % 2 == 0 && m[i / 2] != 0)
                        m[i / 2]--;
                    else
                        return false;
                }
            }
        }
        for (auto i : m)
        {
            if (i.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};