class Solution
{
public:
    /**
     * @param symb: the array of symbols
     * @param oper: the array of operators
     * @return: the number of ways
     */
    int countParenth(string &s, string &a)
    {

        int n = s.length();
        if (n == 0)
            return 0;
        int f[n][n], t[n][n];
        memset(f, 0, sizeof(f));
        memset(t, 0, sizeof(t));
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'T')
            {
                t[i][i] = 1;
            }
            else
            {
                f[i][i] = 1;
            }
        }
        int m = a.size();
        for (int gap = 1; gap < n; gap++)
        {
            for (int l = 0; l < n - gap; l++)
            {
                int r = l + gap;
                for (int i = l; i < r; i++)
                {
                    int k = i;
                    if (a[k] == '&')
                    {
                        t[l][r] += t[l][i] * t[i + 1][r];
                        f[l][r] += f[l][i] * t[i + 1][r] + t[l][i] * f[i + 1][r] + f[l][i] * f[i + 1][r];
                    }
                    else if (a[k] == '|')
                    {
                        f[l][r] += f[l][i] * f[i + 1][r];
                        t[l][r] += f[l][i] * t[i + 1][r] + t[l][i] * f[i + 1][r] + t[l][i] * t[i + 1][r];
                    }
                    else
                    {
                        t[l][r] += f[l][i] * t[i + 1][r] + t[l][i] * f[i + 1][r];
                        f[l][r] += f[l][i] * f[i + 1][r] + t[l][i] * t[i + 1][r];
                    }
                }
            }
        }
        return t[0][n - 1];
    }
};