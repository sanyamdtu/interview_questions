class Solution
{
public:
    struct node
    {
        int val, i, j;
    };
    struct comp
    {
        bool operator()(node a, node b)
        {
            return a.val > b.val;
        }
    };
    vector<int> smallestRange(vector<vector<int>> &arr)
    {
        priority_queue<node, vector<node>, comp> q;
        int n = arr.size();
        int a = INT_MAX, b = INT_MIN, k;
        for (int i = 0; i < n; i++)
        {
            q.push({arr[i][0], i, 0});
            b = max(arr[i][0], b);
            a = min(a, arr[i][0]);
        }
        k = b;
        while (1)
        {
            auto temp = q.top();
            q.pop();
            if (b - a > k - temp.val)
            {
                a = temp.val;
                b = k;
            }
            // cout<<temp.val<<" "<<temp.i<<" "<<temp.j<<" "<<k<<endl;
            if (temp.j == arr[temp.i].size() - 1)
                break;
            k = max(arr[temp.i][temp.j + 1], k);
            q.push({arr[temp.i][temp.j + 1], temp.i, temp.j + 1});
        }
        vector<int> v;
        v = {a, b};
        return v;
    }
};