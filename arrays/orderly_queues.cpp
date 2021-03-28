class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k >= 2)
        {
            sort(s.begin(), s.end());
            return s;
        }
        int n = s.length();
        string b = s;
        for (int i = 0; i < n; i++)
        {
            char a = s[0];
            s.erase(s.begin());
            s += a;
            if (!lexicographical_compare(b.begin(), b.end(), s.begin(), s.end()))
                b = s;
        }
        return b;
    }
};