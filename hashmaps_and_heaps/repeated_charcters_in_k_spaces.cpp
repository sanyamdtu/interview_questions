class Solution
{
public:
    string reorganizeString(string p)
    {
        unordered_map<char, int> m;
        multiset<pair<int, char>> s;
        for (auto i : p)
            m[i]++;
        for (auto i : m)
            s.insert({-i.second, i.first});
        queue<pair<int, char>> q;
        int k = 2;
        string ans = "";
        for (int i = 1; i < k; i++)
        {
            auto a = *(s.begin());
            ans += a.second;
            a.first++;
            q.push(a);
            s.erase(s.begin());
        }
        while (!s.empty())
        {
            auto a = *(s.begin());
            s.erase(s.begin());
            ans += a.second;
            a.first++;
            q.push(a);
            auto temp = q.front();
            q.pop();
            if (temp.first != 0)
                s.insert(temp);
        }
        while (!q.empty())
        {
            auto a = q.front();
            q.pop();
            if (a.first != 0)
                return "";
        }
        return ans;
    }
};