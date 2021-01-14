typedef long long ll;
class Solution
{
public:
    vector<int> gridIllumination(int n, vector<vector<int>> &arr, vector<vector<int>> &a)
    {
        unordered_map<ll, ll> m, r, c, d, u;
        for (auto i : arr)
        {
            m[((1LL) * i[0] * n) + i[1]]++;
            r[i[0]]++;
            c[i[1]]++;
            d[i[0] + i[1]]++;
            u[i[0] - i[1]]++;
        }
        vector<int> v;
        ll dx[] = {1, 0, -1, 0, 1, -1, 1, -1, 0};
        ll dy[] = {0, 1, 0, -1, 1, -1, -1, 1, 0};
        for (auto q : a)
        {
            if (r[q[0]] > 0 || c[q[1]] > 0 || d[q[0] + q[1]] > 0 || u[q[0] - q[1]] > 0)
                v.push_back(1);
            else
                v.push_back(0);
            for (int i = 0; i < 9; i++)
            {
                ll x = dx[i] + q[0];
                ll y = dy[i] + q[1];
                if (x >= 0 && y >= 0 && x < n && y < n && m[x * n + y] == 1)
                {
                    m[x * n + y]--;
                    r[x]--;
                    c[y]--;
                    d[x + y]--;
                    u[x - y]--;
                }
            }
        }
        return v;
    }
};