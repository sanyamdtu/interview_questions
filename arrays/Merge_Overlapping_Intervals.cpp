#include <bits/stdc++.h>
using namespace std;
struct node
{
    int s, e;
};
bool comp(node a, node b)
{
    if (a.s == b.s)
        return (a.e < b.e);
    return (a.s < b.s);
}
int main()
{
    int n;
    cin >> n;
    node arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].s >> arr[i].e;
    }
    sort(arr, arr + n, comp);
    vector<node> ans;
    int a = arr[0].s, b = arr[0].e;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].s <= b)
        {
            b = arr[i].e;
        }
        else
        {
            ans.push_back({a, b});
            a = arr[i].s;
            b = arr[i].e;
        }
    }
    ans.push_back({a, b});
    for (auto i : ans)
    {
        cout << i.s << " " << i.e << endl;
    }
}