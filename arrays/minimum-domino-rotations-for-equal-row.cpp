class Solution
{
public:
    int minDominoRotations(vector<int> &p, vector<int> &q)
    {
        int a, b, c, d, n = p.size();
        a = b = c = d = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i] != p[0] && q[i] != p[0] && q[i] != q[0] && p[i] != q[0])
                return -1;
            a++;
            b++;
            c++;
            d++;
            if (p[i] != p[0] && (q[i] != p[0]))
                a = 100000, b = 100000;
            if (p[i] != q[0] && q[i] != q[0])
                c = 100000, d = 100000;
            if (p[i] == p[0])
                a--;
            if (q[i] == p[0])
                b--;
            if (p[i] == q[0])
                c--;
            if (q[i] == q[0])
                d--;
        }

        int ans = min(a, min(b, min(c, d)));
        if (ans >= 100000)
            return -1;
        return ans;
    }
};