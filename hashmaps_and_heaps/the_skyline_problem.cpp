bool comp(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return (a[1] < b[1]);
    return (a[0] < b[0]);
}
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &v)
    {
        multiset<int, greater<int>> q;
        q.insert(0);
        vector<vector<int>> arr;
        for (auto i : v)
        {
            arr.push_back({i[0], -i[2]});
            arr.push_back({i[1], i[2]});
        }
        sort(arr.begin(), arr.end(), comp);
        vector<vector<int>> ans;
        int curr = 0;
        for (auto i : arr)
        {
            if (i[1] < 0)
            {
                q.insert(-i[1]);
                if (curr < *(q.begin()))
                {
                    ans.push_back({i[0], -i[1]});
                    curr = *(q.begin());
                }
            }
            else
            {
                q.erase(q.find(i[1]));
                if (curr > *(q.begin()))
                {
                    curr = *(q.begin());
                    ans.push_back({i[0], curr});
                }
            }
        }
        return ans;
    }
};