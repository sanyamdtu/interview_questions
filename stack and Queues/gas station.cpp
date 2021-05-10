class Solution
{
public:
    int canCompleteCircuit(vector<int> &g, vector<int> &c)
    {
        int sg = 0, sc = 0, n = g.size(), mini = INT_MAX, ps = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            sg += g[i];
            sc += c[i];
            ps += g[i] - c[i];
            if (ps < mini)
            {
                ans = i;
                mini = ps;
            }
        }
        if (sg < sc)
            return -1;
        return (ans + 1) % n;
    }
};