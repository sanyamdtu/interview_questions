#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x, y;
};
int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    queue<node> q;
    node a = {0, 0};

    unordered_map<string, int> dis;
    dis["0#0"] = 0;
    int ans = 0;
    while (!q.empty())
    {
        auto a = q.front();
        q.pop();
        int c = a.x;
        int d = a.y;
        int wt = dis[to_string(c) + "#" + to_string(d)];
        if ((c == z && d == 0) || (d == z && c == 0))
        {
            ans = min(wt, ans);
            break;
        }
        if (dis[to_string(c) + "#0"] == 0)
        {
            dis[to_string(c) + "#0"] = wt + 1;
            q.push({c, 0});
        }
        if (dis["0#" + to_string(d)] == 0)
        {
            dis["0#" + to_string(d)] = wt + 1;
            q.push({0, d});
        }
        if (dis[to_string(x) + "#" + to_string(d)] == 0)
        {
            dis[to_string(x) + "#" + to_string(d)] = wt + 1;
            q.push({x, d});
        }
        if (dis[to_string(c) + "#" + to_string(y)] == 0)
        {
            dis[to_string(c) + "#" + to_string(y)] = wt + 1;
            q.push({c, y});
        }
        for (int i = 0; i <= max(x, y); i++)
        {
            int u = c + i;
            int v = d - i;
            if (c == x ||)
        }
    }
}