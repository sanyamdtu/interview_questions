class Solution
{
public:
    unordered_map<string, int> m;
    bool func(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        if (s == t)
            return true;
        unordered_map<char, int> a, b;
        for (auto i : s)
            a[i]++;
        for (auto i : t)
            b[i]++;
        for (auto i : a)
            if (b[i.first] != i.second)
                return false;
        int n = s.length();
        if (m[s + "#" + t] != 0)
            return (m[s + "#" + t] == 1);
        for (int i = 1; i < s.length(); i++)
        {
            if (func(s.substr(0, i), t.substr(0, i)) && func(s.substr(i), t.substr(i)))
            {
                m[s + "#" + t] = 1;
                return true;
            }

            if (func(s.substr(0, i), t.substr(n - i)) && func(s.substr(i), t.substr(0, n - i)))
            {
                m[s + "#" + t] = 1;
                return true;
            }
        }
        m[s + "#" + t] = -1;
        return false;
    }
    bool isScramble(string s, string t)
    {
        m.clear();
        return func(s, t);
    }
};