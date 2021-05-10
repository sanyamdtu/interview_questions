class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int i = s.length(), j = t.length(), a = 0, b = 0;
        while (i >= 0 && j >= 0)
        {
            if (s[i] == '#')
                a++, i--;
            else if (t[j] == '#')
                b++, j--;
            else if (a > 0)
            {
                a--, i--;
            }
            else if (b > 0)
                b--, j--;
            else if (s[i] == t[j])
            {
                i--, j--;
            }
            else
                return false;
        }

        while (i >= 0 && (a > 0 || s[i] == '#'))
        {
            if (s[i] == '#')
                a++;
            else
                a--;
            i--;
        }
        while (j >= 0 && (b > 0 || t[j] == '#'))
        {
            if (t[j] == '#')
                b++;
            else
                b--;
            j--;
        }
        return (i == -1 && j == -1);
    }
};