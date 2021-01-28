
class Solution
{
public:
    bool canPair(vector<int> arr, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++)
        {
            int p = (arr[i] % k);
            m[p]++;
        }
        for (auto i : arr)
        {
            int p = (i % k);
            if (m[p] == 0)
                continue;
            m[p]--;
            if (p != 0)
            {

                m[k - p]--;
            }
            else
            {
                m[p]--;
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
