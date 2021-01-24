struct node
{
    int i, j, val;
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
    int kthSmallest(vector<vector<int>> &arr, int k)
    {
        int n = arr.size();
        if (n == 0)
            return 0;
        priority_queue<node, vector<node>, comp> q;
        int c = 1;
        for (int i = 0; i < n; i++)
            q.push({i, 0, arr[i][0]});
        while (c < k)
        {
            c++;
            auto a = q.top();
            q.pop();
            if (a.j != n - 1)
                q.push({a.i, a.j + 1, arr[a.i][a.j + 1]});
        }
        return q.top().val;
    }
};