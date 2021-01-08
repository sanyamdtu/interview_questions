typedef long long ll;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &arr, int k)
    {
        set<pair<ll, ll>> s;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            s.insert({-pow(arr[i][0], 2) - pow(arr[i][1], 2), i});
            if (s.size() == k + 1)
                s.erase(s.begin());
        }
        vector<vector<int>> v;
        while (!s.empty())
        {
            auto a = *(s.begin());
            v.push_back(arr[a.second]);
            s.erase(s.begin());
        }
        return v;
    }
};