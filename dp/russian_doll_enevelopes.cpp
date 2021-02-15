struct node
{
    int l, w;
};
bool comp(node a, node b)
{
    if (a.l == b.l)
        return a.w > b.w;
    return a.l < b.l;
}
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &p)
    {
        int n = p.size();
        if (n == 0)
            return 0;
        node arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i].l = p[i][0];
            arr[i].w = p[i][1];
        }
        sort(arr, arr + n, comp);
        int ans = 0, temp[n];
        for (int i = 0; i < n; i++)
        {
            int lo = 0, hi = ans;
            while (lo < hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (temp[mid] < arr[i].w)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            temp[lo] = arr[i].w;
            if (lo == ans)
                ans++;
        }
        return ans;
    }
};