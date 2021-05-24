typedef long long ll;
struct node
{
    ll val, i;
};
struct comp
{
    bool operator()(node a, node b)
    {
        return a.val > b.val;
    }
};

class Solution
{
public:
    priority_queue<node, vector<node>, comp> p;
    unordered_map<ll, int> m;
    int nthUglyNumber(int n)
    {
        p = priority_queue<node, vector<node>, comp>();
        m.clear();
        int k = 1;
        if (n == 1)
            return 1;
        queue<ll> q[3];
        m[2] = 1;
        m[3] = 1;
        m[5] = 1;
        p.push({2, 0});
        p.push({3, 1});
        p.push({5, 2});
        ll a;
        while (k < n)
        {
            auto temp = p.top();
            p.pop();
            k++;
            a = temp.val;
            ll b = temp.i;
            if (m[a * 2] == 0)
            {
                m[a * 2] = 1;
                q[0].push(a * 2);
            }
            if (m[a * 3] == 0)
            {
                m[a * 3] = 1;
                q[1].push(a * 3);
            }
            if (m[a * 5] == 0)
            {
                m[a * 5] = 1;
                q[2].push(a * 5);
            }
            p.push({q[b].front(), b});
            q[b].pop();
        }
        return a;
    }
};