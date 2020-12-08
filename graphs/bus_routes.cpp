class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &arr, int x, int y)
    {
        int n = arr.size();
        int bus[n];
        memset(bus, 0, sizeof(bus));
        unordered_map<int, int> vis;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++)
        {
            for (auto j : arr[i])
            {
                m[j].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        vis[x] = 1;
        q.push({x, 0});
        while (!q.empty())
        {
            auto a = q.front();
            if (a.first == y)
                return a.second;
            q.pop();
            for (auto i : m[a.first])
            {
                if (bus[i] == 0)
                {
                    for (int j : arr[i])
                    {
                        if (vis[j] == 0)
                        {
                            q.push({j, a.second + 1});
                            vis[j] = 1;
                        }
                    }
                }
                bus[i] = 1;
            }
        }
        return -1;
    }
};