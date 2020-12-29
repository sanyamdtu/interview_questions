class Solution
{
public:
    int find(int x, int p[])
    {
        if (x == p[x])
            return x;
        return p[x] = find(p[x], p);
    }
    void un(int x, int y, int p[], int r[])
    {
        int px = find(x, p);
        int py = find(y, p);
        if (r[px] > r[py])
            p[py] = px;
        else if (r[px] < r[py])
            p[px] = py;
        else
        {
            r[px]++;
            p[py] = x;
        }
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int p[n + 1], r[n + 1];
        int in[n + 1], a = -1, b = -1;
        for (int i = 0; i < n + 1; i++)
        {
            in[i] = -1, r[i] = 1, p[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            if (in[arr[i][1]] == -1)
                in[arr[i][1]] = i;
            else
            {
                a = in[arr[i][1]];
                b = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int x = arr[i][0];
            int y = arr[i][1];
            if (i != b && find(x, p) == find(y, p))
            {
                if (a == -1)
                    return arr[i];
                else
                    return arr[a];
            }
            else if (i != b)
            {
                un(x, y, p, r);
            }
        }
        return arr[b];
    }
};