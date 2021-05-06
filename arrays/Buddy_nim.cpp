#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + m);
        int i = n - 1, j = m - 1, f = 1;
        for (; i >= 0 && j >= 0;)
        {
            if (a[i] == 0)
                i--;
            else if (a[j] == 0)
                j--;
            else if (a[i] != b[j])
            {
                f = 0;
                break;
            }
            else
            {
                i--;
                j--;
            }
        }
        while (i >= 0 && a[i] == 0)
            i--;
        while (j >= 0 && b[j] == 0)
            j--;
        if (i != j)
            f = 0;
        if (f == 0)
        {
            cout << "Alice";
        }
        else
        {
            cout << "Bob";
        }
        cout << endl;
    }
}