#include <bits/stdc++.h>
using namespace std;
int main()
{
    string p, s, a;
    cin >> p;
    for (auto i : p)
    {
        if (i == '+' || i == '*')
            a.push_back(i);
        else
            s.push_back(i);
    }
    int n = s.length();
    int maxi[n][n], mini[n][n];
    memset(mini, 100, sizeof(mini));
    memset(maxi, 0, sizeof(maxi));
    for (int i = 0; i < n; i++)
    {
        maxi[i][i] = s[i] - '0';
        mini[i][i] = s[i] - '0';
    }
    for (int gap = 1; gap < n; gap++)
    {
        for (int l = 0; l < n - gap; l++)
        {
            int r = l + gap;
            for (int i = l; i < r; i++)
            {
                int k = i;
                if (a[k] == '+')
                {
                    maxi[l][r] = max(maxi[l][r], maxi[l][i] + maxi[i + 1][r]);
                    mini[l][r] = min(mini[l][r], mini[l][i] + mini[i + 1][r]);
                }
                else
                {
                    maxi[l][r] = max(maxi[l][r], maxi[l][i] * maxi[i + 1][r]);
                    mini[l][r] = min(mini[l][r], mini[l][i] * mini[i + 1][r]);
                }
            }
        }
    }
    cout << maxi[0][n - 1] << " " << mini[0][n - 1];
}