bool comp(vector<int> a, vector<int> b)
{
    return (a[0] < b[0]);
}
class Solution
{
public:
    /**
     * @param points: n points on a 2D plane
     * @return: if there is such a line parallel to y-axis that reflect the given points
     */

    bool isReflected(vector<vector<int>> &arr)
    {
        sort(arr.begin(), arr.end(), comp);
        if (arr.size() <= 1)
            return true;
        int mid = (arr[0][0] + arr.back()[0]);
        unordered_map<string, int> m;
        for (auto i : arr)
        {
            string a = to_string(i[0]) + "#" + to_string(i[1]);
            if (2 * i[0] != mid)
                m[a] = 1;
        }
        for (auto i : arr)
        {
            string a = to_string(i[0]) + "#" + to_string(i[1]);
            string b = to_string(mid - i[0]) + "#" + to_string(i[1]);
            if (m[a] == 0)
                continue;
            m[a]--;
            if (m[b] == 0)
                return false;
            m[b]--;
        }
        return true;
    }
};