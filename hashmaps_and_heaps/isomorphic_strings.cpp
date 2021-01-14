class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> m, p;
        int n = s.length();
        if (s.length() != t.length())
            return false;
        for (int i = 0; i < n; i++)
        {
            if (m.find(s[i]) != m.end())
            {
                if (m[s[i]] != t[i])
                    return false;
            }
            else
            {
                if (p.find(t[i]) == p.end())
                {
                    m[s[i]] = t[i];
                    p[t[i]] = s[i];
                }
                else
                    return false;
            }
        }
        return true;
    }
};