
class Solution
{
public:
    struct comp
    {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return (a[0] > b[0]);
        }
    };
    int findCheapestPrice(int n, vector<vector<int>> &arr, int u, int v, int k)
    {
        vector<vector<pair<int, int>>> g(n);
        for (auto i : arr)
            g[i[0]].push_back({i[1], i[2]});
        priority_queue<vector<int>, vector<vector<int>>, comp> s;
        s.push({0, u, k + 1});
        while (!s.empty())
        {
            auto a = s.top();
            s.pop();
            int node = a[1], price = a[0], stops = a[2];
            if (node == v)
                return price;
            if (a[2] <= 0)
                continue;
            for (auto i : g[node])
            {
                s.push({price + i.second, i.first, stops - 1});
            }
        }
        return -1;
    }
};