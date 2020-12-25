#include <bits/stdc++.h>
using namespace std;
unordered_map<string, string> par;
unordered_map<string, int> r;
string find(string x)
{
    if (par[x] == x)
        return x;
    return par[x] = find(par[x]);
}
void un(string x, string y)
{
    string px = find(x);
    string py = find(y);
    if (px != py)
    {
        if (r[px] > r[py])
        {
            par[py] = px;
        }
        else if (r[px] < r[py])
        {
            par[px] = py;
        }
        else
        {
            par[py] = px;
            r[px]++;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<string> a, b;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        b.push_back(t);
    }

    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        string p, q;
        cin >> p >> q;
        if (r.find(p) == r.end())
        {
            r[p] = 1;
            par[p] = p;
        }
        if (r.find(q) == r.end())
        {
            r[q] = 1;
            par[q] = q;
        }
        un(p, q);
    }
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (find(a[i]) != find(b[i]))
            f = 1;
    }
    if (f == 0)
        cout << "Yes";
    else
        cout << "NO";
}