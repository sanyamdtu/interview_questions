
struct node
{
    int s, e, i, j;
};
struct comp
{
    bool operator()(node a, node b)
    {
        return a.s > b.s;
    }
};
class Solution
{
public:
    vector<Interval> employeeFreeTime(vector<vector<int>> &arr)
    {
        priority_queue<node, vector<node>, comp> q;
        for (int i = 0; i < arr.size(); i++)
        {
            if (!arr[i].empty())
            {
                node a = {arr[i][0], arr[i][1], i, 1};
                q.push(a);
            }
        }
        vector<vector<int>> ans;
        int endtime = q.top().s;
        while (!q.empty())
        {
            auto a = q.top();
            q.pop();
            if (endtime < a.s)
            {
                ans.push_back({endtime, a.s});
            }
            if ((a.j) + 1 < arr[a.i].size())
                q.push({arr[a.i][a.j + 1], arr[a.i][a.j + 2], a.i, a.j + 2});
            endtime = max(endtime, a.e);
        }
        vector<Interval> res;
        for (auto i : ans)
        {
            Interval a(i[0], i[1]);
            res.push_back(a);
        }
        return res;
    }
};