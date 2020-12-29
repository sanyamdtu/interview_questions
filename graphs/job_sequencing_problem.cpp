bool comp(Job a, Job b)
{
    if (a.profit == b.profit)
        return a.dead > b.dead;
    return a.profit > b.profit;
}
int find(int x, int p[])
{
    if (x == -1)
        return -1;
    if (x == p[x])
        return x;
    return p[x] = find(p[x], p);
}
void un(int x, int y, int p[])
{
    int py = find(y, p);
    p[x] = py;
}
pair<int, int> JobScheduling(Job arr[], int n)
{
    int ans = 0;
    int c = 0;
    sort(arr, arr + n, comp);
    int p[n];
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < n; i++)
    {
        int idx = find(min(arr[i].dead - 1, n - 1), p);
        if (idx == -1)
            continue;
        else
        {
            c++;
            ans += arr[i].profit;
            un(idx, idx - 1, p);
        }
    }
    pair<int, int> res;
    res.first = c;
    res.second = ans;
    return res;
}
