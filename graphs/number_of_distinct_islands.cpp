class Solution
{
public:
    int ladderLength(string x, string y, vector<string> &arr)
    {
        unordered_map<string, int> vis, temp, dist;
        for (auto i : arr)
        {
            temp[i] = 1;
        }
        queue<string> q;
        q.push(x);
        dist[x] = 1;
        vis[x] = true;
        while (!q.empty())
        {
            auto a = q.front();
            // cout<<a<<endl;
            q.pop();
            if (a == y)
                return dist[y];
            for (int i = 0; i < a.length(); i++)
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    string k = a;
                    k[i] = ch;
                    if (temp[k] == 1 && vis[k] == 0)
                    {
                        dist[k] = dist[a] + 1;
                        q.push(k);
                        vis[k] = 1;
                    }
                }
            }
        }
        return 0;
    }
};