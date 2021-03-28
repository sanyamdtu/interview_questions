class Solution
{
public:
    bool isLongPressedName(string s, string t)
    {
        int n = s.length(), m = t.length();
        if (s[0] != t[0])
            return false;
        int i = 1, j = 1;
        for (; i < n; i++, j++)
        {
            while (j < m && s[i] != t[j] && (t[j] == t[j - 1]))
                j++;
            if (j == m || (s[i] != t[j]))
                return false;
        }
        while (j < m && (t[j] == t[j - 1]))
            j++;
        return (j == m);
    }
};