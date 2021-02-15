
struct node
{
    int l, h, w;
};
bool comp(node a, node b)
{
    if (a.l == b.l)
        return (a.w > b.w);
    return (a.l < b.l);
}
int maxHeight(int height[], int width[], int length[], int m)
{
    int n = 3 * m;
    node arr[n];
    for (int i = 0, j = 0; j < m; j++)
    {
        arr[i].h = width[j];
        arr[i].l = min(length[j], height[j]);
        arr[i].w = max(length[j], height[j]);
        i++;
        arr[i].h = height[j];
        arr[i].l = min(length[j], width[j]);
        arr[i].w = max(length[j], width[j]);
        i++;
        arr[i].h = length[j];
        arr[i].l = min(width[j], height[j]);
        arr[i].w = max(width[j], height[j]);
        i++;
    }
    sort(arr, arr + n, comp);
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = arr[i].h;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i].w > arr[j].w)
                dp[i] = max(dp[i], arr[i].h + dp[j]);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}