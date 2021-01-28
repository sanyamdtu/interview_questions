vector<int> e;
struct node
{
    int i, j;
};
struct comp
{
    bool operator()(node a, node b)
    {
        int p = e[a.i] * e[b.j];
        int q = e[b.i] * e[a.j];
        return p > q;
    }
};
class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        int n = arr.size();
        e = arr;
        vector<int> ans;
        if (n == 0)
            return ans;
        priority_queue<node, vector<node>, comp> q;
        for (int i = 0; i < n - 1; i++)
            q.push({i, n - 1});
        int c = 1;
        while (c < k)
        {
            c++;
            auto a = q.top();
            q.pop();
            if (a.i != a.j - 1)
                q.push({a.i, a.j - 1});
        }
        ans = {arr[q.top().i], arr[q.top().j]};
        return ans;
    }
};