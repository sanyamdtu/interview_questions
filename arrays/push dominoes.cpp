class Solution
{
public:
    string pushDominoes(string a)
    {
        string s = "L";
        s += a;
        s += 'R';
        string ans = "";
        int n = s.length();
        for (int k = 0, i = 0, j = 1; j < n; j++)
        {
            if (s[j] == '.')
            {
                continue;
            }
            else
            {
                if (s[i] == 'L' && s[j] == 'L')
                {
                    while (k < j)
                    {
                        ans += 'L';
                        k++;
                    }
                }
                else if (s[i] == 'R' && s[j] == 'R')
                {
                    while (k < j)
                    {
                        ans += 'R';
                        k++;
                    }
                }
                else if (s[i] == 'L' && s[j] == 'R')
                {
                    ans += 'L';
                    k++;
                    while (k < j)
                    {
                        ans += '.';
                        k++;
                    }
                }
                else
                {
                    int c = j - i + 1;
                    int p = 0;
                    while (p < (c / 2))
                    {
                        ans += 'R';
                        k++;
                        p++;
                    }
                    if (c % 2 == 1)
                    {
                        ans += '.';
                        k++;
                        p++;
                    }
                    while (p < (c - 1))
                    {
                        ans += 'L';
                        k++;
                        p++;
                    }
                }
                i = j;
            }
        }
        string ab = ans.substr(1, n - 2);
        return ab;
    }
};