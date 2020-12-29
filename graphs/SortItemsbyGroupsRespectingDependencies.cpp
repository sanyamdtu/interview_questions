class Solution
{
public:
    vector<int> sortItems(int n, int m, vector<int> &a, vector<vector<int>> &p)
    {
        vector<vector<int>> g(n + (2 * m));
        for (int i = 0; i < n; i++)
        {
            if (a[i] != -1)
            {
                g[n + (2 * a[i])].push_back(i);
                g[i].push_back(n + (2 * a[i]) + 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            for (auto j : p[i])
            {
                int y = a[j];
                if (x != -1)
                    x = n + (2 * a[i]);
                else
                    x = i;
                if (y != -1)
                    y = n + (2 * a[j]) + 1;
                else
                    y = j;
                if (a[i] != a[j])
                    g[y].push_back(x);
                else
                    g[j].push_back(i);
            }
        }
        int in[n + (2 * m)];
        memset(in, 0, sizeof(in));
        for (int i = 0; i < n + (2 * m); i++)
        {
            for (auto j : g[i])
            {
                in[j]++;
            }
        }
        queue<int> q;
        vector<int> res;
        for (int i = 0; i < n + (2 * m); i++)
        {
            if (in[i] == 0)
            {
                in[i] = -1;
                q.push(i);
                while (!q.empty())
                {
                    int a = q.front();
                    if (a < n)
                        res.push_back(a);
                    q.pop();
                    for (auto i : g[a])
                    {
                        in[i]--;
                        if (in[i] == 0)
                        {
                            q.push(i);
                            in[i] = -1;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n + 2 * m; i++)
        {
            if (in[i] > 0)
            {
                vector<int> s;
                return s;
            }
        }
        return res;
    }
};